#include <stdio.h>
#include <vector>
#define mod 1000000

using namespace std;

// >> 1500000
void getPisano(unsigned long long n) {
  vector<int> v = {0, 1, 1};
  unsigned long long period = 2;
  while(++period) {
    v.push_back((v[period - 1] + v[period - 2]) % mod);
    if(v[period] % mod == 1 && v[period - 1] % mod == 0) {
      printf("%d", v[n % (period - 1)] % mod);
      return;
    }
  }
}

int main() {
  unsigned long long n;
  scanf("%llu", &n);
  getPisano(n);
}