# BFS : 너비 우선 탐색
트리나 그래프를 탐색하는 방법으로 한 쪽 경로의 끝까지 같은 다른 경로를 가는 방식을 사용한다.  
한 쪽 경로를 타고 내려가는 것으로 재귀의 방식을 사용한다.

```c++
bool visit[1000];

int dfs(int q) {
  if(q == 0) return;
  if(!visit[nextQ]) return dfs(q);
}
```

관련 알고리즘 : [DP](./dp.md), [Backtraing](./backtracking.md)