// [골드] LCS
#include <iostream>
using namespace std;

#define INF 0x3f3f3f3f;

int dp[1001][1001];

void chmin(int &origin, int comp) {
  if (origin > comp) {
    origin = comp;
  }
}

int main() {
  string a, b;
  cin >> a >> b;

  for (int i = 0; i <= a.length(); ++i) {
    for (int j = 0; j <= b.length(); ++j) {
      if (i != 0 || j != 0) dp[i][j] = INF;
      if (i > 0) chmin(dp[i][j], dp[i - 1][j] + 1);  // 위
      if (j > 0) chmin(dp[i][j], dp[i][j - 1] + 1);  // 왼
      if (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1])
          chmin(dp[i][j], dp[i - 1][j - 1]);
        else
          chmin(dp[i][j], dp[i - 1][j - 1] + 1);
      }
    }
  }

//   for (int i = 0; i <= a.length(); ++i) {
//     for (int j = 0; j <= b.length(); ++j) {
//       cout << dp[i][j] << " ";
//     }
//     cout << endl;
//   }

  printf("%d\n", dp[a.length()][b.length()]);
  return 0;
}