#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

vector<string> mapV;
vector<vector<vector<int>>> visitV;
vector<pair<int, int>> door;
vector<pair<int, int>> mirror;

int n;

struct state {
  int i;
  int j;
  bool ver;
  bool pos;
  int cnt;
  state(int a, int b, bool c, bool d, int e) {
    i = a;
    j = b;
    ver = c;
    pos = d;
    cnt = e;
  };
};

bool inZone(int i, int j) {
  return i >= 0 && j >= 0 && i < n && j < n && mapV[i][j] != '*';
}

int main() {
  cin >> n;
  mapV.assign(n, "");
  visitV.assign(n, vector<vector<int>>(n, vector<int>(2, 0)));
  for(int i = 0; i < n; i++) {
    cin >> mapV[i];
    for(int j = 0; j < n; j++) {
      if(mapV[i][j] == '#') door.push_back(make_pair(i, j));
      if(mapV[i][j] == '!') mirror.push_back(make_pair(i, j));
    }
  }
  queue<state> q;
  q.push(state(door[0].first, door[0].second, 0, 0, 0));
  q.push(state(door[0].first, door[0].second, 0, 1, 0));
  q.push(state(door[0].first, door[0].second, 1, 0, 0));
  q.push(state(door[0].first, door[0].second, 1, 1, 0));
  while(q.size()) {
    state s = q.front();
    int mi = s.ver;
    int mj = !s.ver;
    if(!s.pos) {
      mi = -mi;
      mj = -mj;
    }
    int ni = s.i + mi;
    int nj = s.j + mj;
    while(inZone(ni, nj)) {
      if(mapV[ni][nj] == '!') {
        if(visitV[ni][nj][!s.ver] >= s.cnt && s.cnt) break;
        q.push(state(ni, nj, !s.ver, true, s.cnt + 1));
        q.push(state(ni, nj, !s.ver, false, s.cnt + 1));
        visitV[ni][nj][!s.ver] = s.cnt;
      }
      if(door[1].first == ni && door[1].second == nj) {
        cout << s.cnt;
        return 0;
      }
      ni += mi;
      nj += mj;
    }
    q.pop();
  }
}  