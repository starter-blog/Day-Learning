#include <iostream>
#include <vector>

using namespace std;

vector<int> memoryV;
vector<int> costV;
vector<vector<unsigned int>> memo;

int n, m;

int max(int a, int b) {
  return a > b ? a : b;
}

//memo[i][cost] = maxMem
unsigned int knapsack(int i, int cost) {
  if(i == 0) return memo[i][cost] = costV[0] <= cost ? memoryV[0] : 0;
  if(memo[i][cost]) return memo[i][cost];
  if(costV[i] > cost) return memo[i][cost] = knapsack(i - 1, cost);
  return memo[i][cost] = max(knapsack(i - 1, cost), knapsack(i - 1, cost - costV[i]) + memoryV[i]);
}

int main() {
  int sum = 0;
  cin >> n >> m;
  memoryV.assign(n, 0);
  costV.assign(n, 0);
  for(int i = 0; i < n; i++) {
    cin >> memoryV[i];
  }  
  for(int i = 0; i < n; i++) {
    cin >> costV[i];
    sum += costV[i];
  }
  memo.assign(n, vector<unsigned int>(sum + 1, 0));
  for(int maxCost = 0; maxCost <= sum; maxCost++) {
    int result = knapsack(n - 1, maxCost);
    if(result >= m) {
      cout << maxCost; 
      break;
    }
  }
}