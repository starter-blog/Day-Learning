#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct m {
  int sum = 0;
  queue<int> list;
};

vector<m> v(1002);

int n, start;

int main() {
  cin >> n;
  while(n--) {
    cin >> start;
    int tmp = start;
    int nsum = v[start].sum + 1;
    queue<int> nlist = v[start].list;
    nlist.push(start);
    while(tmp <= 1000 && nsum >= v[++tmp].sum) {
      v[tmp].sum = nsum;
      v[tmp].list = nlist;
    }
  }
  cout << v[1001].list.size() << endl;
  while(v[1001].list.size()) {
    cout << v[1001].list.front() << " ";
    v[1001].list.pop();
  }
}