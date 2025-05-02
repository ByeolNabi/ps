// [골드] LCS
#include <iostream>
using namespace std;

int dp[1001][1001];

void chmax(int &origin, int comp) {
  if (origin < comp) {
    origin = comp;
  }
}

int main() {
  string a, b;
  cin >> a >> b;

  for (int i = 1; i <= b.length(); ++i) {
    for (int j = 1; j <= a.length(); ++j) {
      if (a[j-1] == b[i-1]) {
        chmax(dp[i][j], dp[i - 1][j - 1] + 1);
      } else {
        chmax(dp[i][j], dp[i - 1][j]);
        chmax(dp[i][j], dp[i][j - 1]);
      }
    }
  }

  //   for (int i = 0; i < b.length(); ++i) {
  //     for (int j = 0; j < a.length(); ++j) {
  //       cout << dp[i][j] << " ";
  //     }
  //     cout << endl;
  //   }

  printf("%d\n", dp[b.length()][a.length()]);
  return 0;
}