//[골드5] 다각형의 면적
#include <cmath>
#include <iostream>
using namespace std;
// 신발끈 공식 1*4 더하기, 2*3 빼기

int main() {
  long long total = 0;
  int N;
  scanf("%d", &N);

  // init
  long long p0[2], p1[2], p2[2];
  long long *ptr1 = p1, *ptr2 = p2;
  scanf("%lld %lld", &p0[0], &p0[1]);
  p1[0] = p0[0];
  p1[1] = p0[1];

  // 신발끈 연산
  for (int i = 1; i < N; i++) {
    scanf("%lld %lld", &ptr2[0], &ptr2[1]);

    total += (ptr1[0] * ptr2[1]) - (ptr2[0] * ptr1[1]);
    ptr1 = (ptr1 == p1 ? p2 : p1);
    ptr2 = (ptr2 == p2 ? p1 : p2);
  }

  // 마지막 연산
  ptr2 = p0;
  total += (ptr1[0] * ptr2[1]) - (ptr2[0] * ptr1[1]);

  printf("%.1lf\n", abs(round(total / 2. * 10) / 10));
  return 0;
}