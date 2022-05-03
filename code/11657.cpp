//1번에서 갈 수 없는 싸이클은 의미가 없음
#include <iostream>
#include <vector>

using namespace std;

vector<vector<long long>> d;
vector<vector<bool>> l;
int n, m, a, b, c; 

int main() {
  cin >> n >> m;
  l.assign(n + 1, vector<bool>(n + 1, false));
  d.assign(n + 1, vector<long long>(n + 1, 6000 * 10000 + 1));
  for(int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    d[a][b] = d[a][b] < c ? d[a][b] : c;
    l[a][b] = true;
  }
  for(int j = 1; j <= n; j++) {
    for(int i = 1; i <= n; i++) {
      for(int k = 1; k <= n; k++) {
        if(l[i][j] && l[j][k]) {
          d[i][k] = d[i][k] < d[i][j] + d[j][k] ? d[i][k] : d[i][j] + d[j][k];
          l[i][k] = true;
        }
      }
    }
  }
  for(int i = 1; i <= n; i++) {
    if(d[i][i] < 0 && l[1][i]) {
      cout << -1;
      return 0;
    }
  }
  for(int i = 2; i <= n; i++) {
    if(d[1][i] == 6000 * 10000 + 1) cout << -1 << endl;
    else cout << d[1][i] << endl;
  }
}