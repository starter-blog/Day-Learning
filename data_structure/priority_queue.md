# Priority Queue : 우선 순위 큐

1. [우선 순위 큐의 정의](#우선-순위-큐의-정의)
2. [우선 순위 큐의 선언](#우선-순위-큐의-선언)
3. [우선 순위 큐의 정렬](#우선-순위-큐의-정렬)
4. [우선 순위 큐의 삽입](#우선-순위-큐의-삽입)
5. [우선 순위 큐의 삭제](#우선-순위-큐의-삽입)
6. [우선 순위 큐의 연산](#우선-순위-큐의-연산)
***
## 우선 순위 큐의 정의
우선 순위 큐는 정해진 기준으로 우선 순위를 할당하고 그 우선 순위에 따라 처리한다.  
우선 순위 끝부분을 top으로 한다. 

## 우선 순위 큐의 선언
```c++
#include <queue>

int main() {
  priority_queue<template> q;
  priority_queue<template, template, struct> q;
  //<형식, q의 형식, 정렬 기준>을 의미
  //정렬 기준에 greater<int> 시 역순 정렬
}
```

## 우선 순위 큐의 정렬
```c++
struct compare {
  bool operator()(int l, int r) {
    return l > r;
  }
};

int main() {
  priority_queue<int, vector<int>, compare> q;
  priority_queue<int, vector<int>, greater<int>> q;
}
```

## 우선 순위 큐의 삽입
```c++
q.push(value);
```

## 우선 순위 큐의 삭제
삭제 연산은 `top`에서 `pop` 과정을 통해 진행된다.
```c++
q.pop(); //큐가 비어있을 시 오류 발생
```

## 우선 순위 큐의 연산
```c++
q.top();
q.empty();
q.size();
```