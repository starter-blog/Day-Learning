#include <iostream>
#include <vector>
#define modN 1000000003
using namespace std;

vector<vector<int>> memo;

int dp(int i, int k, int n) {
  if(2 * k - 1 == n - i + 1) return 1;
  if(2 * k - 1 > n - i + 1) return 0;
  if(k == 0) return 1;
  if(i >= n) return 0;
  if(memo[i][k]) return memo[i][k];
  return memo[i][k] = (dp(i + 2, k - 1, n) % modN + dp(i + 1, k, n) % modN) % modN;
}

int main() {
  int n, k, result;
  cin >> n >> k;
  memo.assign(n + 1, vector<int>(k + 1, 0));
  result = dp(3, k - 1, n - 1) % modN;
  memo.assign(n + 1, vector<int>(k + 1, 0));
  cout << (result + dp(2, k, n) % modN) % modN;
}