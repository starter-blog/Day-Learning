# Map

1. [맵의 정의](#맵의-정의)
2. [맵의 선언](#맵의-선언)
3. [맵의 연산](#맵의-연산)
***
## 맵의 정의
키 값과 밸류 값으로 이뤄진 쌍의 값

## 맵의 선언
```c++
#include <map>

int main() {
  map<template, template> m;
}
```

## 맵의 삽입
```c++
map.insert(make_pair(key, value));
map[key] = value;
```

## 스택의 연산
```c++
m.count(key);
m.size();
```
