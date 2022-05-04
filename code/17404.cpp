#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, ic;
vector<vector<int>> memo;
vector<vector<int>> rgb;

int dp(int i, int color) {
  if(i == n - 1) {
    return ic == color ? 1001 : rgb[i][color];
  }
  if(memo[i][color]) return memo[i][color];
  if(color == 0) return memo[i][color] = rgb[i][color] + min(dp(i + 1, 1), dp(i + 1, 2));
  if(color == 1) return memo[i][color] = rgb[i][color] +  min(dp(i + 1, 0), dp(i + 1, 2));
  if(color == 2) return memo[i][color] = rgb[i][color] +  min(dp(i + 1, 0), dp(i + 1, 1));
}

/*
1번 집의 색은 2번, N번 집의 색과 같지 않아야 한다.
N번 집의 색은 N-1번, 1번 집의 색과 같지 않아야 한다.
i(2 ≤ i ≤ N-1)번 집의 색은 i-1, i+1번 집의 색과 같지 않아야 한다.
*/

int main() {
  cin >> n;
  memo.assign(n, vector<int>(3, 0));
  rgb.assign(n, vector<int>(3, 0));
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < 3; j++) {
      cin >> rgb[i][j];
    }
  }
  priority_queue<int, vector<int>, greater<int>> result;
  ic = 0;
  result.push(dp(0, 0));
  memo.assign(n, vector<int>(3, 0));
  ic = 1;
  result.push(dp(0, 1));
  memo.assign(n, vector<int>(3, 0));
  ic = 2;
  result.push(dp(0, 2));
  cout << result.top();
}