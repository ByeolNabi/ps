#include <cmath>
#include <iostream>
using namespace std;

const unsigned long long r = 31, M = 1234567891;

unsigned long long power(unsigned long long base, int exp) {
  unsigned long long res = 1;
  base %= M;  // base를 먼저 M으로 나눈 나머지를 취합니다.
  while (exp > 0) {
    if (exp % 2 == 1) res = (res * base) % M;
    base = (base * base) % M;
    exp /= 2;
  }
  return res;
}

unsigned long long hash_output(string str) {
  unsigned long long hash_result = 0;
  for (int i = 0; i < str.length(); ++i) {
    unsigned long long term = (str[i] - 'a' + 1);
    unsigned long long power_of_r = power(r, i);
    hash_result = (hash_result + (term * power_of_r) % M) % M;
  }
  return hash_result;
}

int main() {
  int length;
  scanf("%d", &length);
  string str;
  cin >> str;
  printf("%llu\n", hash_output(str));
  return 0;
}

// 모듈러 분배법칙을 이용해서 연산을 줄여야한다.