## DP : Dynamic Programing (동적 계획법)

큰 문제를 작은 문제로 쪼개어 해결하는 방법으로  
중복되는 부분에 대하여 값을 저장, 재활용하는 데 포커싱을 둔다.

EX ) 피보나치 수열의 구현
```
#include <stdio.h>

int dp[100];

int fibonachi(n) {
  if(n <= 1) return n;
  if(dp[n] != n) return dp[n];
  dp[n] = fibonachi(n - 1) + fibonachi(n - 2);
  return dp[n];
}
```
관련 알고리즘 : [Knapsack](https:\\), [Memoization](https:\\)