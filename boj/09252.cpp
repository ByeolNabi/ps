// LCS인데 0.1초 + 문자열도 찾아야 함
#include <iostream>
using namespace std;

int dp[1001][1001];

int main() {
  string top, left;
  cin >> top >> left;

  for (int i = 1; i <= left.length(); i++) {
    for (int j = 1; j <= top.length(); j++) {
      if (left[i - 1] == top[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;  // 대각선에서 끌어오기
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  for (int i = 0; i <= left.length(); i++) {
    for (int j = 0; j <= top.length(); j++) {
      printf("%d ", dp[i][j]);
    }
    printf("\n");
  }

  return 0;
}

/*
복원 알고리즘을 어떻게 해야할까?
=>
*/
