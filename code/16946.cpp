#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

vector<pair<int, int>> parent;
vector<vector<int>> mapV;

int n, m;
int di[] = {-1,0,0,1};
int dj[] = {0,-1,1,0};

bool inZone(int i, int j) {
  return i >= 0 && j >= 0 && i < n && j < m;
}

int union_find(int x) {
  if(x == parent[x].first) return x;
  return parent[x].first = union_find(parent[x].first);
}

void union_merge(int l, int r) {
  l = union_find(l);
  r = union_find(r);
  if(l != r) {
    parent[r].second += parent[l].second;
    parent[l] = parent[r];
  }
}

int main() {
  cin >> n >> m;
  mapV.assign(n, vector<int>(m, 0));
  parent.assign(1000000, pair<int, int>());
  for(int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for(int j = 0; j < m; j++) {
      mapV[i][j] = s[j] == '1';
      parent[1000 * i + j] = make_pair(1000 * i + j, 1);
      if(mapV[i][j] == 0) {
        for(int k = 0; k < 2; k++) {
          int ni = i + di[k];
          int nj = j + dj[k];
          if(inZone(ni, nj) && mapV[ni][nj] == 0) {
            union_merge(1000 * i + j, 1000 * ni + nj);
          }
        }
      }
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(mapV[i][j]) {
        set<int> area;
        for(int k = 0; k < 4; k++) {
          int ni = i + di[k];
          int nj = j + dj[k];
          if(inZone(ni, nj) && mapV[ni][nj] == 0) {
            area.insert(union_find(1000 * ni + nj));
          }
        }
        for(auto a = area.begin(); a != area.end(); a++) 
          mapV[i][j] += parent[*a].second % 10;
      }
      printf("%d", mapV[i][j] % 10);
    }
    printf("\n");
  }
}