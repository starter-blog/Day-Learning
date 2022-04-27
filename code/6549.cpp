#include <stdio.h>
#include <vector>

using namespace std;

int main() {
  int n;
  while(1) {
    //h, index
    vector<pair<unsigned long long, int>> rec;
    vector<int> h;
    unsigned long long result = 0;
    scanf("%d", &n);
    if(n == 0) return 0;
    
    for(int i = 0; i < n; i++) {
      unsigned long long tmp;
      scanf("%llu", &tmp);
      if(rec.empty() || rec[rec.size() - 1].first < tmp) {
        rec.push_back(make_pair(tmp, i));
      } 
      else {
        for(int j = rec.size() - 1; j >= 0; j--) {
          unsigned long long area = rec[j].first * (i - rec[j].second);
          if(result < area) result = area;
          if(rec[j].first < tmp) {
            rec[j + 1].first = tmp;
            rec.resize(j + 2);
            break;
          }
          if(j == 0) {
            rec[j].first = tmp;
            rec.resize(1);
            break;
          }
        }
      }
    }   
    for(int i = 0; i < rec.size(); i++) {
      unsigned long long area = rec[i].first * (n - rec[i].second);
      if(result < area) result = area;
    }
    printf("%llu\n", result);
  }
}