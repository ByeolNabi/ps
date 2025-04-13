// DP[골드3] 최소 편집
#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <class T>
void board(T &arr) {
  for (int i = 0; i < arr.size(); i++) {
    for (int j = 0; j < arr[0].size(); ++j) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}

template <class T>
void chmin(T &dst, T val) {
  if (dst > val) {
    dst = val;
  }
}

const int INF = 1 << 30;

int main() {
  string start, dst;
  cin >> start >> dst;

  // dp[start사이즈+1, dst사이즈+1] 그런데 INF로 채워진
  vector<vector<int>> dp(start.size() + 1, vector<int>(dst.size() + 1, INF));

  dp[0][0] = 0;
  for (int i = 0; i <= start.size(); ++i) {
    for (int j = 0; j <= dst.size(); ++j) {
      // start 기준으로
      // 대체
      if (i > 0 && j > 0) {
        if (start[i - 1] == dst[j - 1]) {
          // i, j에 대해 각각 -1을 해야한다.
          chmin(dp[i][j], dp[i - 1][j - 1]);
        } else {
          chmin(dp[i][j], dp[i - 1][j - 1] + 1);
        }
      }
      // start에서 삽입
      if (j > 0) {  // dst 문자열이 공백이라면 그 이전은 없기 때문에
        chmin(dp[i][j], dp[i][j - 1] + 1);
      }

      // start에서 삭제
      if (i > 0) {  // start 문자열이 공백이라면 그 이전은 없기 때문에
        chmin(dp[i][j], dp[i - 1][j] + 1);
      }
    }
  }

  // board(dp);

  printf("%d\n", dp[start.size()][dst.size()]);
  return 0;
}