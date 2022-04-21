# Divide And Conquer : 분할 정복 알고리즘
문제를 하위 문제로 분할하여 정복하고 하단에서 조합하는 형태

```c++
int square(int n, int pow) {
  if(pow == 0) return 1;

  int divide = square(n, pow / 2);
  if(pow % 2) return divide * divide * n;
  else return divide * devide
}