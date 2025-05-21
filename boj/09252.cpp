// LCS인데 0.1초 + 문자열도 찾아야 함
#include <iostream>
using namespace std;

int dp[1001][1001];

string dfs(string str, int row, int col) {
  // 바닥 조건
  if (dp[row][col] == 0) {
    return "";
  }
  // 일반 조건
  if (dp[row][col] == dp[row - 1][col]) {
    return dfs(str, row - 1, col);
  } else if (dp[row][col] == dp[row][col - 1]) {
    return dfs(str, row, col - 1);
  }
  // cout << row << " : " << col << endl;
  return dfs(str, row - 1, col - 1) + str[col - 1];
}

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

  // for (int i = 0; i <= left.length(); i++) {
  //   for (int j = 0; j <= top.length(); j++) {
  //     printf("%d ", dp[i][j]);
  //   }
  //   printf("\n");
  // }

  cout << dp[left.length()][top.length()] << "\n";
  if (dp[left.length()][top.length()] != 0) {
    cout << dfs(top, left.length(), top.length()) << "\n";
  }

  return 0;
}

/*
복원 알고리즘을 어떻게 해야할까?
=> BFS!! 모서리 숫자 찾기, 찾으면 -1,-1방향으로 이동
0 A C A Y K P
C 0 1 1 1 1 1
A 1 1 2 2 2 2
P 1 1 2 2 2 3
C 1 2 2 2 2 3
A 1 2 3 3 3 3
K 1 2 3 3 4 4

*/
