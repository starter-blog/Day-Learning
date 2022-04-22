#include <stdio.h>
#include <vector>

using namespace std;

int n;

vector<vector<int>> mul(vector<vector<int>> l, vector<vector<int>> r) {
  vector<vector<int>> result(n, vector<int>(n, 0));
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      for(int k = 0; k < n; k++) {
        result[i][j] += l[i][k] * r[k][j] % 1000;
      }
    }
  }
  return result;
}

vector<vector<int>> square(vector<vector<int>> v, long pow) {
  if(pow == 1) return v;
  if(pow == 2) {
    vector<vector<int>> result(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        for(int k = 0; k < n; k++) {
          result[i][j] += v[i][k] * v[k][j] % 1000;
        }
      }
    }
    return result;
  }
  vector<vector<int>> a = square(v, pow / 2); 
  vector<vector<int>> result(n, vector<int>(n, 0));
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      for(int k = 0; k < n; k++) {
        result[i][j] += a[i][k] * a[k][j] % 1000;
      }
    }
  }
  if(pow % 2) return mul(result, v);
  else return result;
}

int main() {
  int tmp;
  long long pow;
  scanf("%d %lld", &n, &pow);
  vector<vector<int>> v;
  for(int i = 0; i < n; i++) {
    vector<int> temp;
    for(int j = 0; j < n; j++) {
      scanf("%d", &tmp);
      temp.push_back(tmp);
    }
    v.push_back(temp);
  }
  vector<vector<int>> result = square(v, pow);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      printf("%d ", result[i][j] % 1000);
    }
    printf("\n");
  }
}