#include <iostream>
#include <vector>

using namespace std;

vector<vector<unsigned int>> memo;
vector<vector<int>> matrix;

unsigned int dp(int start, int end) {
  if(start == end) return 0;
  if(end - start == 1)
    return memo[start][end] = matrix[start][0] * matrix[end][0] * matrix[end][1];
  if(memo[start][end]) 
    return memo[start][end];
  unsigned int min = -1;
  for(int i = start; i < end; i++) {
    unsigned tmpMin = dp(start, i) + dp(i + 1, end) + matrix[start][0] * matrix[i][1] * matrix[end][1];
    if(min >= tmpMin) {
      min = tmpMin;
      memo[start][end] = tmpMin;
    }
  }
  return memo[start][end];
}

int main() {
  int n;
  cin >> n;
  memo.assign(n, vector<unsigned int>(n, 0));
  matrix.assign(n, vector<int>(2, 0));
  for(int i = 0; i < n; i++) {
    cin >> matrix[i][0] >> matrix[i][1];
  } cout << dp(0, n - 1);
}