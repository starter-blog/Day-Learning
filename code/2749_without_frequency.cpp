#include <stdio.h>
#include <vector>

using namespace std;  
vector<vector<int>> v = { {1, 1}, {1, 0} };

vector<vector<unsigned long long>> mul(vector<vector<unsigned long long>> l) {
  vector<vector<unsigned long long>> result = {{0, 0}, {0, 0}};
  for(int i = 0; i < 2; i++) {
    for(int j = 0; j < 2; j++) {
      for(int k = 0; k < 2; k++) {
        result[i][j] += l[i][k] * v[k][j] % 1000000;
      }
    }
  }
  return result;
}

vector<vector<unsigned long long>> square(unsigned long long pow) {
  if(pow <= 1) return { {1, 1}, {1, 0} };
  if(pow == 2) {
    vector<vector<unsigned long long>> result = {{0, 0}, {0, 0}};
    for(int i = 0; i < 2; i++) {
      for(int j = 0; j < 2; j++) {
        for(int k = 0; k < 2; k++) {
          result[i][j] += v[i][k] * v[k][j] % 1000000;
        }
      }
    }
    return result;
  }
  vector<vector<unsigned long long>> a = square(pow / 2); 
  vector<vector<unsigned long long>> result = {{0, 0}, {0, 0}};
  for(int i = 0; i < 2; i++) {
    for(int j = 0; j < 2; j++) {
      for(int k = 0; k < 2; k++) {
        result[i][j] += a[i][k] * a[k][j] % 1000000;
      }
    }
  }
  if(pow % 2) return mul(result);
  else return result;
}

int main() {
  unsigned long long n;
  scanf("%llu", &n);   
  vector<vector<unsigned long long>> result = square(n - 1);
  printf("%llu", result[0][0] % 1000000);
}