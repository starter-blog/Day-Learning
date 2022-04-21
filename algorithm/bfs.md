# BFS : 너비 우선 탐색
트리나 그래프를 탐색하는 방법으로 동일 레벨의 노드를 돈 후 다음 레벨로 내려가는 방식을 의미한다.  
이를 위해서는 선입선출(FIFO) 방식이 필요하여 queue를 사용한다.

```c++
#include <queue>

queue<int> q;

int bfs() {
  while(q.size()) {
    int f = q.front();

    //F에 맞는 행동을 한 후 F 밑에 행동을 한다.
    //queue에 넣는 것이므로 높은 레벨에 있던 것이 다 해결한 후 자식들이 행동한다.
    act(f);
    q.push(getChild(f));
    
    q.pop();
  }
}
```

관련 자료구조 : [Queue](../data_structure/queue.md)