# Dijkstra : 가중치 최소 알고리즘
가중치가 있는 간선으로 이루어진 그래프에서 시작 노드에서 종착 노드까지의 최소값을 구하는 알고리즘
```c++
int main() {
  for(int j = 0; j < n; j++) {
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        v[i][k] = v[i][k] < v[i][j] + v[j][k] ? v[i][k] : v[i][j] + v[j][k];
      }
    }
  }
}
```