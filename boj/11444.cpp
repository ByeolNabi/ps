// [골드2] 피보나치 수 6
#include <iostream>
#include <vector>
using namespace std;

using MAT = vector<vector<unsigned long long>>;
#define DVSR 1000000007
const unsigned long long F0 = 0;
const unsigned long long F1 = 1;

// mod가 10억... n이 100경...
// 100경의 피보나치 수를 찾으려면 mem을 100경번 해야하는거 아닌가?
// 피보나치 배열 제곱으로 표현하기...?

MAT mat_mul(MAT first, MAT second) {
  MAT result = {{0, 0}, {0, 0}};
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      for (int k = 0; k < 2; ++k) {  // i,j를 계산하기 위한 곱더곱 순환
        result[i][j] = (result[i][j] +
                        ((first[i][k] % DVSR) * (second[k][j] % DVSR)) % DVSR) %
                       DVSR;  // [i행 안에서 1,2] [i열 안에서 1,2]
      }
    }
  }

  return result;
}

// 분할정복 거듭제곱 (밑을 늘려가는 형식)
MAT mat_pow(MAT base, unsigned long long exp) {
  MAT coefficient = {{1, 0}, {0, 1}};
  while (exp > 0) {
    if (exp % 2 == 1) {  // 밑 하나를 계수로 뺀다.
      coefficient = mat_mul(coefficient, base);
      exp -= 1;
    } else {  // 밑은 제곱한다.
      base = mat_mul(base, base);
      exp /= 2;
    }
  }
  return coefficient;
}

unsigned long long fibo_remain(unsigned long long n) {
  MAT m = mat_pow({{1, 1}, {1, 0}}, n - 1);
  return m[0][0];
}

int main() {
  unsigned long long n;
  cin >> n;

  printf("%llu\n", fibo_remain(n));

  return 0;
}