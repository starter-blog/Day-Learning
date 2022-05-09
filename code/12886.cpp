#include <iostream>
#include <vector>

using namespace std;

vector<vector<bool>> visit;

bool dfs(int a, int b, int c) {
  if(visit[a][b]) return 0;
  visit[a][b] = 1;
  if(a == b && b == c) return 1;
  bool result = false;
  
  if(a < b) result |= dfs(a + a, b - a, c);
  else result |= dfs(a - b, b + b, c);
  if(result) return result;
  
  if(a < c) result |= dfs(a + a, b, c - a);
  else result |= dfs(a - c, b, c + c);
  if(result) return result;
  
  if(b < c) result |= dfs(a, b + b, c - b);
  else result |= dfs(a, b - c, c + c);
  return result;
}

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  visit.assign(a + b + c + 1, vector<bool>(a + b + c + 1, 0));
  if((a + b + c) % 3 == 0 && dfs(a, b, c)) {
    cout << 1;
    return 0;
  } 
  cout << 0;
}