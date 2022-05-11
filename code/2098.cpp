#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct cq {
  int n;
  int cost;
  int bit = 0;

  cq(int a, int b, int c) {
    n = a;
    cost = b;
    bit = c | 1 << a;
  }
};

struct compare {
  bool operator()(cq a, cq b) {
    return a.cost >= b.cost;
  }
};

vector<vector<bool>> visit;
vector<vector<int>> w;
priority_queue<cq, vector<cq>, compare> q;

int main() {
  int n, mbit;
  cin >> n;
  mbit = (1 << n) - 1;
  visit.assign(mbit + 1, vector<bool>(n, false));
  w.assign(n, vector<int>(n, 0));
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> w[i][j];
    }
  }
  for(int i = 1; i < n; i++) {
    if(w[0][i])
      q.push(cq(i, w[0][i], 0));
  }
  while(q.size()) {
    cq top = q.top();
    q.pop();
    if(visit[top.bit][top.n]) {
      continue;
    }
    visit[top.bit][top.n] = true;
    if(top.bit == mbit) {
      cout << top.cost;
      break;
    }
    if(top.bit == mbit - 1) {
      if(w[top.n][0])
        q.push(cq(0, top.cost + w[top.n][0], top.bit));
      continue;
    } 
    for(int i = 1; i < n; i++) {
      if(w[top.n][i] && !(top.bit & 1 << i))
        q.push(cq(i, top.cost + w[top.n][i], top.bit));
    }
  }
}