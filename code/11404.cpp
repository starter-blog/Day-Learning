#include <iostream>
#include <vector>
#include <map>

using namespace std;

int maxN = 100 * 100000 + 1;
int result = maxN;

vector<vector<int>> d;

int main() {
  int n, m, a, b, c;
  cin >> n >> m;
  d.assign(n + 1, vector<int>(n + 1, maxN));
  for(int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    d[a][b] = d[a][b] < c ? d[a][b] : c;
  }
  for(int i = 1; i <= n; i++) {
    d[i][i] = 0;
  }
  for(int j = 1; j <= n; j++) {
    for(int i = 1; i <= n; i++) {
      for(int k = 1; k <= n; k++) {
        if(d[i][j] < maxN && d[j][k] < maxN)
          d[i][k] = d[i][k] < d[i][j] + d[j][k] ? d[i][k] : d[i][j] + d[j][k];
      }
    }
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      if(d[i][j] == maxN) cout << 0 << " ";
      else cout << d[i][j] << " ";
    }
    cout << endl;
  }
}