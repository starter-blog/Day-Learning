#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stdio.h>

using namespace std;

int r, c, n;
int dr[] = {0, 0, -1, 1};
int dc[] = {-1, 1, 0, 0};

vector<string> m;
vector<vector<int>> value;
vector<vector<int>> visit;
vector<pair<int, int>> mass;

bool inZone(int i, int j) {
  return i >= 0 && i < r && j >= 0 && j < c;
}

//dfs = 떨어지는 덩어리 구하기
bool find_mass(int startR, int startC) {
  if(!inZone(startR, startC) || m[startR][startC] == '.') return false;
  if(value[startR][startC]) return true;
  if(visit[startR][startC]) return false; 
  visit[startR][startC] = true;
  for(int i = 0; i < 4; i++) {
    if(find_mass(startR + dr[i], startC + dc[i])) return true;
  }  
  mass.push_back(make_pair(startR, startC));  
  return false;
}

//bfs = 낙하 멈추는 지점 찾기
void drop() {
  vector<pair<int, int>> massc = mass;
  queue<pair<int, int>> vc;
  bool dropping = true;
  do {
    visit.assign(r, vector<int>(c));
    for(int i = 0; i < massc.size(); i++) {
      m[massc[i].first][massc[i].second] = '.';
      massc[i].first += 1;
      if(value[massc[i].first][massc[i].second])
        vc.push(make_pair(massc[i].first, massc[i].second));
    }
    for(int i = 0; i < massc.size(); i++) {
      m[massc[i].first][massc[i].second] = 'x';
    }
  } while(!find_mass(massc[0].first, massc[0].second));
  while(vc.size()) {
    int tr = vc.front().first;
    int tc = vc.front().second;
    while(tr > 0 && m[tr][tc] == 'x') {
      value[--tr][tc] = 1;
    }
    vc.pop();
  }
  mass.clear();
}

void throwPick(int t, int h) {
  visit.assign(r, vector<int>(c));
  mass.clear();
  // <-
  if(t % 2) {
    for(int j = c - 1; j >= 0; j--) {
      if(m[r - h][j] == 'x') {
        m[r - h][j] = '.';
        for(int th = r - h - 1; th >= 0; th--) {
          value[th][j] = 0;
        }
        for(int i = 0; i < 4; i++) {
          if(find_mass(r - h + dr[i], j + dc[i])) mass.clear();
          else if(mass.size()) drop();
        }
        break;
      }
    }
  }
  // ->
  else {
    for(int j = 0; j < c; j++) {
      if(m[r - h][j] == 'x') {
        m[r - h][j] = '.';
        for(int th = r - h - 1; th >= 0; th--) {
          value[th][j] = 0;
        }
        for(int i = 0; i < 4; i++) {
          if(find_mass(r - h + dr[i], j + dc[i])) mass.clear();
          else if(mass.size()) drop();
        }
        break;
      }
    }
  }
}

int main() {
  int h;
  string s;

  cin >> r >> c;
  value.assign(r, vector<int>(c));

  for(int i = 0; i < r; i++) {
    cin >> s;
    m.push_back(s);
  }
  
  cin >> n;

  for(int i = r - 1; i > 0; i--) {
    for(int j = 0; j < c; j++) {
      if(i == r - 1) value[i][j] = 1;
      if(m[i][j] == 'x' && value[i][j])
        value[i - 1][j] = 1;
    }
  }
  
  for(int t = 0; t < n; t++) {
    cin >> h;    
    throwPick(t, h);
  }
  
  for(int i = 0; i < r - 1; i++) {
    cout << m[i] << endl;
  } cout << m[r - 1];
}