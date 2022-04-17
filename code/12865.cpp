#include <iostream>
#include <vector>

using namespace std;

int m[100][100001]; //m[물건 최대 + 1][용량 최대 + 1]
int w[100], v[100]; //w = 물건의 무게, v = 물건의 가치
  
int dp(int n, int k) {
  if(n < 0) return 0;
  if(m[n][k]) return m[n][k];
  if(k - w[n] < 0) return dp(n - 1, k);
  int l = dp(n - 1, k);
  int r = dp(n - 1, k - w[n]) + v[n];
  m[n][k] = l > r ? l : r;
  return m[n][k];
}

int main() {
  int n, k; //n = 물건의 종류, k = 가방의 용량

  cin >> n >> k;
  
  for(int i = 0; i < n; i++) {
    cin >> w[i] >> v[i];
  }
  
  cout << dp(n - 1, k);
}