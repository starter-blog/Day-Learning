#include <iostream>
#include <vector>

using namespace std;

vector<vector<pair<unsigned int, unsigned int>>> memo;
vector<int> v;

pair<unsigned int, int> dp (int start, int end) {
  if(memo[start][end].first) 
    return memo[start][end];
  if(start == end - 1) {
    memo[start][end].first = v[start] + v[end];
    memo[start][end].second = v[start] + v[end];
    return memo[start][end];
  }
  unsigned int min = -1;
  for(int pos = start; pos < end; pos++) {
    pair<unsigned int, unsigned int> left = dp(start, pos);
    pair<unsigned int, unsigned int> right = dp(pos + 1, end);
    unsigned tmpMin = left.first + right.first + left.second + right.second;
    if(tmpMin < min) {
      min = tmpMin;
      memo[start][end] = make_pair(left.first + right.first, min);
    }
  }
  return memo[start][end];
}


int main() {
  int n, k;
  cin >> n;
  while(n--) {
    int result = 0, tmp;
    cin >> k;
    v.assign(k, 0);
    memo.assign(k, vector<pair<unsigned int, unsigned int>>(k, make_pair(0, 0)));
    for(int i = 0; i < k; i++) {
      cin >> v[i];
      memo[i][i].first = v[i];
    }
    cout << dp(0, k - 1).second << '\n';
  }
}