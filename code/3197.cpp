#include <iostream>
#include <queue>
#include <string>

using namespace std;

int r, c;
vector<pair<int, int>> swan;
vector<string> m;
int parent[15011501];
  int visit[1501][1501];

int union_find(int x) {
  if (parent[x] == x) return x;
  return parent[x] = union_find(parent[x]);
}

void union_merge(int left, int right) {
  left = union_find(left);
  right = union_find(right);

  if(left != right) {
    if(left > right) {
      parent[left] = right;
    } else parent[right] = left;
  }
}

bool isBorder(int x, int y) {
  return !((x == 0 || m[x - 1][y] != 'X') && (x == r - 1 || m[x + 1][y] != 'X') && (y == 0 || m[x][y - 1] != 'X') && (y == c - 1 || m[x][y + 1] != 'X'));
}

int transPair(pair<int, int> p) {
  return p.first * 10000 + p.second;
}

int bfs(queue<pair<int, int>> nextQ) {
  int result = 0;
  int dx[] = {-1, 1, 0, 0};
  int dy[] = {0, 0, -1, 1};
  pair<int, int> nowI;
  pair<int, int> nextI;
  queue<pair<int, int>> q;
  
  do {
    q.swap(nextQ);
    result++;
    while(q.size()) {
    //녹이고
      nowI = q.front();
      for(int i = 0; i < 4; i++) {
        nextI = make_pair(nowI.first + dx[i], nowI.second + dy[i]);
        if(nextI.first < 0 || nextI.first >= r || nextI.second < 0 || nextI.second >= c) continue;
        if(isBorder(nextI.first, nextI.second) && m[nextI.first][nextI.second] == 'X') nextQ.push(nextI);
        union_merge(transPair(nextI), transPair(nowI));
        m[nextI.first][nextI.second] = '.';
      }
    //확인
      visit[nowI.first][nowI.second] = result;      
      q.pop();
    }    
    if(union_find(transPair(swan[0])) == union_find(transPair(swan[1]))) 
      return result;
  } while(nextQ.size()); 
  return result;
}

int main() {
  queue<pair<int, int>> q;
  cin >> r >> c;

  for (int i = 0; i < r; i++) {
    string s = "";
    cin >> s;
    m.push_back(s);
  }
  for(int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if(m[i][j] == 'L') swan.push_back(make_pair(i, j));
      parent[i * 10000 + j] = i * 10000 + j;
      if(m[i][j] != 'X') {
        if(i > 0 && m[i - 1][j] != 'X') union_merge((i - 1)*10000 + j, i * 10000 + j);
        if(j > 0 && m[i][j - 1] != 'X') union_merge(i * 10000 + j - 1, i * 10000 + j);
        if(isBorder(i, j)) q.push(make_pair(i, j));
      }
    }
  }
  cout << bfs(q);
}