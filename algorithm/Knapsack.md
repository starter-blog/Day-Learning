## Knapsack : 배낭 문제
용량이 정해진 배낭에 무게와 가치가 정해진 물건을 넣는 문제로 크게 3가지로 분류 가능
1. [물건을 나눌 수 있는 경우](#물건을-나눌-수-있는-경우)
2. [물건을 나눌 수 없는 경우](#2번의-경우)
    * 관련 문제 : [12865](../code/12865.cpp)
3. 그 외 특수 조건이 있는 경우
***
### 물건을 나눌 수 없는 경우
[Greed 알고리즘](./Greed.md)을 사용하여 무게 대비 가치가 높은 것들부터 넣는다.
```c++
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  
}
```
***
### 2번의 경우
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
관련 알고리즘 : [DP](./DP.md), [Memoization](./Memoization.md)