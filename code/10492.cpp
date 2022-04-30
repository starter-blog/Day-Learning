#include <stdio.h>
#include <vector>

using namespace std;

vector<vector<int>> memo;
vector<int> v;
int n, m;

int pail(int s, int e) {
  if(s == e) return true;
  if(memo[s][e]) return memo[s][e];
  if(v[s] != v[e]) return memo[s][e] = -1;
  if(s + 1 == e) return memo[s][e] = 1;
  return memo[s][e] = pail(s + 1, e - 1);
}

int main() {
  scanf("%d", &n);
  memo.assign(n, vector<int>(n, 0));
  v.assign(n, 0);
  for(int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  scanf("%d", &m);
  while(m--) {
    int s, e;
    scanf("%d %d", &s, &e);
    printf("%d\n", pail(s - 1, e - 1) > 0);
  }
}