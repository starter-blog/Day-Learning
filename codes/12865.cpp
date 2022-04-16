#include <stdio.h>

int n, k;
int dp[100];
int w[100];
int v[100];
int maxv = 0;

int dp(int nw, int nv, int i) {
  if(i == n) return nv;
  if(nw < w[i]) {
    return dp(nw, nv, i + 1);
  }
  else {
    if(nv + v[i] > maxv) maxv = nv + v[i];
    int a = dp(nw - w[i], nv + v[i], i + 1);
    int b = dp(nw, nv, i + 1);
    return a > b ? a : b;
  }
}

int main() {
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; i++) {
    scanf("%d %d", &w[i], &v[i]);
  }
  dp(k, 0, 0);
  printf("%d\n", maxv);
}