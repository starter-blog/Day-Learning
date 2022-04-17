# Vector : 벡터

1. [벡터의 정의](#벡터의-정의)
2. [벡터의 장단점](#벡터의-장단점)
3. [벡터의 선언](#벡터의-선언)
4. [벡터의 삽입](#벡터의-삽입)
5. [벡터의 삭제](#벡터의-삭제)
6. [벡터의 연산](#벡터의-연산)
   1. [size와 capacity](#size와-capacity)
   2. [iterator](#iterator)

## 벡터의 정의
벡터란 동적 할당 배열로 크기가 정해지지 않은 배열로 생각하면 쉽다.

## 벡터의 장단점
> 벡터의 장점 : 인덱스를 통한 접근이 가능, 크기 변환이 자유로움  
> 벡터의 단점 : 중간 삽입, 삭제가 어려움

## 벡터의 선언
```c++
#include <vector>

//vetor의 선언
vector<template> v;
vector<template> v(n);
vector<template> v(n, defaultValue);
vector<template> v = {1, 2, 3};

v.assign(n, defaultValue);
```

## 벡터의 삽입
```c++
v.push_back(i);
v.insert(iter, n, value);
v.insert(iter, value); //삽입한 곳의 iterator 반환
```

## 벡터의 삭제
```c++
v.pop_back(); //맨 뒤 원소 제거
v.erase(iter); //iter가 가리키는 원소 제거, 메모리는 유지
v.clear(); //모든 원소 제거
```

## 벡터의 연산
### size와 capacity
`v.size()` : 원소의 개수를 리턴
`v.capacity()` : 할당된 공간의 크기를 리턴 (공간이 부족할 때 마다 **2배**씩)

```c++
//size 관련
v.resize(n);
v.resize(n, defaultValue)
v.empty();

//capacity 관련
v2.swap(v1) //capacity를 교환
```
### iterator
```c++
//iter : 주소를 의미
v.begin(); //첫번째를 가리킴
v.end(); //마지막의 다음을 가리킴
v.rbegin(); //reverse begin
v.rend(); //reverse end

v.erase(iter);
```
`*v[n]` = `v.begin() + n`