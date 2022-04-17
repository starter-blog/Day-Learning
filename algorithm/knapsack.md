## Knapsack : 배낭 문제
용량이 정해진 배낭에 무게와 가치가 정해진 물건을 넣는 문제로 크게 3가지로 분류 가능
1. [물건을 나눌 수 있는 경우](#물건을-나눌-수-있는-경우)
2. [물건을 나눌 수 없는 경우](#물건을-나눌-수-없는-경우)
    * 관련 문제 : [12865](../code/12865.cpp)
3. 그 외 특수 조건이 있는 경우
***
### 물건을 나눌 수 있는 경우
[Greed 알고리즘](./greed.md)을 사용하여 무게 대비 가치가 높은 것들부터 넣는다.
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
0-1 knapsack 문제라고도 불리며, [DP](../algorithm/dp.md)를 사용하여 해결한다.  
[Backtracking](../algorithm/backtracking.md)기법으로 해결할 수 있지만,  
시간 복잡도로 인해 지양한다.  
<br>
2차원 배열을 이용하여 **특정 물체가 들어간 경우** vs **들어가지 않은 경우**로 나누어  
남은 물건의 개수와 남은 물건의 용량을 가지고 재귀하며 문제를 풀어 나간다.  

|물건|무게|가치|
|:--:|:--:|:--:|
|A|1kg|3$|
|B|2kg|4$|
|C|3kg|6$|
|D|3kg|7$|

|가방 여유 용량|0kg|1kg|2kg|3kg|4kg|5kg|
|:--:|:--:|:--:|:--:|:--:|:--:|:--:|
|해당 물건들로<br>얻을 수 있는 가치|0|0|0|0|0|0|
|A|0||3$|3$||3$|
|AB|0||A(2kg) VS A(0kg) + 4$|||A(5kg) VS A(3kg) + 4$|
|ABC|0||AB(2kg)|||AB(5kg) VS AB(2kg) + 6$|
|ABCD|0|||||ABC(5kg) VS ABC(2kg) + 7$|

```c++
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
```
관련 알고리즘 : [DP](./dp.md), [Greed](../algorithm/greed.md), [Backtracking](./backtracking.md)