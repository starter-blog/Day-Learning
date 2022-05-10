# Set

1. [셋의 정의](#셋의-정의)
2. [셋의 선언](#셋의-선언)
3. [셋의 연산](#셋의-연산)
***
## 셋의 정의
중복이 없는 집합

## 셋의 선언
```c++
#include <set>

int main() {
  set<template> s;
}
```

## 셋의 삽입
```c++
s.insert(value));
```

## 셋의 연산
```c++
s.count(key);
s.size();
//set은 인덱스의 순서가 없어서 탐색시 begin, end를 사용
for(auto i = s.begin(); i != s.end(); i++) {
  int value = *i;
  ...
}
```