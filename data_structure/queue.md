# Queue

1. [큐의 정의](#큐의-정의)
2. [큐의 선언](#큐의-선언)
3. [큐의 삽입](#큐의-삽입)
4. [큐의 연산](#큐의-연산)
***
## 큐의 정의
`Queue : 대기줄`  

대기줄은 줄을 먼저 선 사람부터 들어가는 것처럼  
큐는 선입선출(FIFO = First In First Out) 방식을 따른다.  
줄의 머리부분을 `front`, 꼬리부분을 `back` 혹은 `rear`라고 한다.  

## 큐의 선언
```c++
#include <queue>

int main() {
  queue<template> q;
}
```

## 큐의 삽입
삽입 연산은 `back` 혹은 `rear`에서 `enQueue` 혹은 `push` 과정을 통해 진행된다.
```c++
q.push(value);
```

## 큐의 삭제
삭제 연산은 `front`에서 `deQueue` 혹은 `pop` 과정을 통해 진행된다.
```c++
q.pop(); //큐가 비어있을 시 오류 발생
```

## 큐의 연산
```c++
q.front();
q.back();
q.empty();
q.size();
```