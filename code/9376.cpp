#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <map>

using namespace std;

vector<int> parent;
vector<string> mapV;

int h, w;
int di[] = {-1,1,0,0};
int dj[] = {0,0,-1,1};

struct regS {
  bool isDoor = false;
  int parent = -1;
  unsigned int min = -1;
};

int union_find(int x) {
  if (parent[x] == -1) return -1;
  if (parent[x] == x) return x;
  return parent[x] = union_find(parent[x]);
}

int union_find(int i, int j) {
  int x = 100 * i + j;
  if (parent[x] == -1) return -1;
  if (parent[x] == x) return x;
  return parent[x] = union_find(parent[x]);
}

void union_merge(int li, int lj, int ri, int rj) {
  int l = union_find(100 * li + lj);
  int r = union_find(100 * ri + rj);

  if(l != r) {
    if(l == -1) parent[r] = -1;
    else if (r == -1) parent[l] = -1;
    else parent[l] = parent[r];
  }
}

bool inZone(int i, int j) {
  return i >= 0 && i < h && j >= 0 && j < w;
}

map<int, int> bfs(int startNode, map<int, vector<int>> graph) {
  map<int, int> result;
  queue<regS> regQ;

  regS first;
  if(startNode != -1)
    first.parent = parent[startNode];
  first.min = 0;
  regQ.push(first);
  result[startNode] = 0;

  do {
    regS start = regQ.front();
    vector<int> v = graph[start.parent];
    
    for (int i = 0; i < v.size(); i++) {
      regS next;
      next.parent = v[i];
      if(v[i] != -1)
        next.isDoor = mapV[v[i] / 100][v[i] % 100] == '#';
      next.min = start.min + next.isDoor;
      if(!result.count(v[i])) result.insert(make_pair(v[i], next.min));
      else if(result[v[i]] > next.min) {
        result[v[i]] = next.min;
      }
      else continue;
      regQ.push(next);
    }
    regQ.pop();
  } while(regQ.size());
  return result;
}

int main() {
  int n;
  cin >> n;
  while(n--) {
    vector<pair<int, int>> door;
    vector<int> thief;

    map<int, vector<int>> graph;    
    set<int> region;

    cin >> h >> w;
    
    mapV.assign(h, "");    
    parent.assign(10001, 0);
    
    for(int i = 0; i < h; i++) {
      cin >> mapV[i];
      for(int j = 0; j < w; j++) {
        if(mapV[i][j] == '#') door.push_back(make_pair(i, j));
        if(mapV[i][j] == '$') thief.push_back(100 * i + j);
        if((mapV[i][j] == '.' || mapV[i][j] == '$') && (i == 0 || j == 0 || i == h - 1 || j == w - 1)) parent[100 * i + j] = -1;
        else parent[100 * i + j] = 100 * i + j;
      }
    }
    
    for(int i = 0; i < h; i++) {
      for(int j = 0; j < w; j++) {
        if(mapV[i][j] == '.' || mapV[i][j] == '$') {
          for(int k = 0; k < 4; k++) {
            int ni = i + di[k];
            int nj = j + dj[k];
            if(!inZone(ni, nj)) parent[100 * i  + j] = -1; 
            else if(mapV[ni][nj] == '.' || mapV[ni][nj] == '$') 
              union_merge(i, j, ni, nj);
          }
        }
      }
    }
    
    region.insert(-1);
    for(int d = 0; d < door.size(); d++) {
      int i = door[d].first;
      int j = door[d].second;
      region.insert(union_find(100 * i + j));
      for(int k = 0; k < 4; k++) {
        int ni = i + di[k];
        int nj = j + dj[k];
        if(!inZone(ni, nj)) {
          graph[-1].push_back(100 * i + j);
          graph[100 * i + j].push_back(-1);
        }
        else if(mapV[ni][nj] != '*') {
          region.insert(union_find(100 * ni + nj));        
          graph[parent[100 * ni + nj]].push_back(parent[100 * i + j]);
          graph[parent[100 * i + j]].push_back(parent[100 * ni + nj]);
        }
      }
    }
    
    map<int, int> tmp0 = bfs(-1, graph);
    map<int, int> tmp1 = bfs(parent[thief[0]], graph);
    map<int, int> tmp2 = bfs(parent[thief[1]], graph);
        
    unsigned int min = -1;
    
    for(auto i = region.begin(); i != region.end(); i++) {
      int index = *i;
      int result = tmp0[index] + tmp1[index] + tmp2[index];
      if(mapV[index / 100][index % 100] == '#') result -= 2;
      if(min > result) min = result;
    }   
    printf("%d\n", min);
  }
}