## Knapsack : 배낭 문제
용량이 정해진 배낭에 무게와 가치가 정해진 물건을 넣는 문제로 크게 3가지로 분류 가능
1. [물건을 나눌 수 있는 경우](#물건을-나눌-수-있는-경우)
2. [물건을 나눌 수 없는 경우](#물건을-나눌-수-없는-경우)
    * 관련 문제 : [12865](../code/12865.cpp)
3. 그 외 특수 조건이 있는 경우
***
### 물건을 나눌 수 있는 경우
[Greed 알고리즘](./Greed.md)을 사용하여 무게 대비 가치가 높은 것들부터 넣는다.
```c++
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 무게 대비 가치가 높은 순으로 정렬
bool compare(pair<int, int> l, pair<int, int> r) {
  if(l.first > 0 && r.first > 0 && l.second / l.first > r.second / r.first) {
    return true;
  } 
  return false;
}

int main() {
  double result = 0;
  double n, k; //n = 물건의 종류, k = 가방의 용량
  double c, v; //c = 물건의 무게, v = 물건의 가치
  vector<pair<double, double>> obj = {}; //obj = 물건 벡터
  
  cin >> n >> k;
  
  for(int i = 0; i < n; i++) {
    cin >> c >> v;
    obj.push_back(make_pair(c,v));
  }

  sort(obj.begin(), obj.end(), compare);
  
  for(int i = 0; k > 0 && i < n; i++) {
    double nn = obj[i].first;
    
    if(k < nn) 
      nn = k;
    
    result += obj[i].second * nn / obj[i].first;
    k -= nn;
  }
  cout << result;
}
```
***
### 물건을 나눌 수 없는 경우
```c++
#include <stdio.h>

int dp[100];

int fibonachi(n) {
  if(n <= 1) return n;
  if(dp[n] != n) return dp[n];
  dp[n] = fibonachi(n - 1) + fibonachi(n - 2);
  return dp[n];
}
```
관련 알고리즘 : [DP](./dp.md), [Memoization](./memoization.md)