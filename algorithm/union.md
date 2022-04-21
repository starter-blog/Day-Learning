# Union : 부분 집합
값들이 뿌리를 가지고 있을 때 이를 비교하는 용도로 사용된다.  
ex) 영역

```c++
int parent[n] = {1,2,3, ... n}; 

//찾기
int union_find(int x) {
  if(parent[x] == x) return x;
  return parent[x] = union_find(parent[x]);
}

//합치기
void union_merge(int x, int y) {
  x = union_find(x);
  y = union_find(y);

  if(x == y) return;
  else parent[x] = y;
}
```