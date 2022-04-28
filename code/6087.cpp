#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

struct s {
  int i;
  int j;
  int cost;
  bool hr;
  s(int a, int b, int c, bool d) {
    i = a;
    j = b;
    cost = c;
    hr = d;
  }
};

vector<string> mapV;
vector<pair<int, int>> target;
vector<vector<unsigned int>> costV;

queue<s> q;
int h, w;

bool inZone(int i, int j) {
  return i >= 0 && j >= 0 && i < h && j < w;
}

int main() {
  cin >> w >> h;
  mapV.assign(h, "");
  costV.assign(h, vector<unsigned int>(w, -1));
  for(int i = 0; i < h; i++) {
    cin >> mapV[i];
    for(int j = 0; j < w; j++) {
      if(mapV[i][j] == 'C') {
        target.push_back(make_pair(i, j));
      }
    }
  }

  q.push(s(target[0].first, target[0].second, -1, true));
  q.push(s(target[0].first, target[0].second, -1, false));

  while(q.size()) {
    s now = q.front();
    bool nhr = now.hr;
    int ni = now.i + !now.hr;
    int nj = now.j + now.hr;
    int nc = now.cost + 1;
    while(inZone(ni, nj) && mapV[ni][nj] != '*' && costV[ni][nj] >= nc) {
      if(target[1].first == ni && target[1].second == nj) {
        cout << nc;
        return 0;
      }
      q.push(s(ni,nj,nc,!nhr));
      costV[ni][nj] = nc;
      ni += !now.hr;
      nj += now.hr;
    }
    
    ni = now.i - !now.hr;
    nj = now.j - now.hr;    
    while(inZone(ni, nj) && mapV[ni][nj] != '*' && costV[ni][nj] >= nc) {
      if(target[1].first == ni && target[1].second == nj) {
        cout << nc;
        return 0;
      }
      q.push(s(ni,nj,nc,!nhr));
      costV[ni][nj] = nc;      
      ni -= !now.hr;
      nj -= now.hr;      
    }
    
    q.pop();
  }
}