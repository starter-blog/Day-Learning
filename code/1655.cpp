#include <stdio.h>
#include <queue>

using namespace std;

//high는 역순 정렬
struct compare {
  bool operator()(int l, int r) {
    return l > r;
  }
};

int main() {
	priority_queue<int> low;
  priority_queue<int, vector<int>, compare> high;
  // = priority_queue<int, vectir<int>, greater<int>> high;
  
	int n, tmp;
	scanf("%d", &n); //cin은 속도가 느림

  for (int i = 0; i < n; i++) {
    scanf("%d", &tmp);
    if(low.size() > high.size())
      high.push(tmp);
    else low.push(tmp);
    
    //emprty 확인 안하면 high.top 에러
    if(!high.empty() && low.top() > high.top()) {
      int temp = low.top();
      low.pop();
      low.push(high.top());
      high.pop();
      high.push(temp);
    }

    //cout시 속도가 느림
    printf("%d\n", low.top());
	}
}