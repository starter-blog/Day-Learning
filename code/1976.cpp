#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

int union_find(int x) {
  if(x == parent[x]) return x;
  return parent[x] = union_find(parent[x]);
}

void union_merge(int x, int y) {
  x = union_find(x);
  y = union_find(y);
  if(x != y) parent[x] = y;
}

int main() {
  int n, m, tmp, result;
  cin >> n >> m;
  for(int i = 0; i < n; i++)
    parent.push_back(i);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> tmp;
      if(tmp) {
        union_merge(i, j);
      }
    }
  }
  for(int i = 0; i < m; i++) {
    cin >> tmp;
    tmp -= 1;
    if(i == 0) result = union_find(tmp);
    else if(result != union_find(tmp)) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
}