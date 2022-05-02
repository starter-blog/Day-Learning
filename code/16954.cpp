#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;
vector<string> mapV(8, "");
vector<vector<vector<bool>>> visit(8, vector<vector<bool>>(8, vector<bool>(8, false)));

int n = 8;
int di[] = {-1, 0, 1};
int dj[] = {-1, 0, 1};

bool inZone(int i, int j) {
  return i >= 0 && j >= 0 && i < n && j < n;
}

bool canGo(int i, int j, int t) {
  int ri = i - t;
  if(!inZone(i, j)) return false;
  if(visit[i][j][t]) return false;
  visit[i][j][t] = true;
  return mapV[ri][j] == '.' && (!ri || mapV[ri - 1][j] == '.');
}

bool dfs(int pi, int pj, int pt) {
  if(pi - pt <= 0) return true;
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      int ni = pi + di[i];
      int nj = pj + dj[j];
      int nt = pt + 1;
      if(canGo(ni, nj, pt) && dfs(ni, nj, nt)) return true;
    }
  }
  return false;
}

int main() {
  for(int i = 0; i < n; i++) {
    cin >> mapV[i];
  }
  cout << dfs(7, 0, 0);
}