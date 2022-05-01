#include <iostream>
#include <vector>
#include <map>

using namespace std;

int maxN = 400 * 10000 + 1;
int result = maxN;

vector<vector<int>> d;

int main() {
  int v, e, a, b, c; 
  cin >> v >> e;
  d.assign(v + 1, vector<int>(v + 1, maxN));
  for(int i = 0; i < e; i++) {
    cin >> a >> b >> c;
    d[a][b] = c;
  }
  for(int i = 1; i <= v; i++) {
    for(int j = 1; j <= v; j++) {
      for(int k = 1; k <= v; k++) {
        if(d[i][j] < maxN && d[j][k] < maxN)
        d[i][k] = d[i][k] < d[i][j] + d[j][k] ? d[i][k] : d[i][j] + d[j][k];
      }
    }
  }
  for(int i = 1; i <= v; i++) {
    result = result < d[i][i] ? result : d[i][i];
  }
  if(result == maxN) cout << "-1";
  else cout << result;
}