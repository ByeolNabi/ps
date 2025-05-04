// [골드5] 평범한 배낭
#include <algorithm>
#include <iostream>
using namespace std;

int dp[101][100001];
pair<int, int> item[101];

int main() {
  int N, K;  // 물품, 무게
  scanf("%d %d", &N, &K);
  int W, V;  // 아이템 무게, 가치
  for (int i = 0; i < N; ++i) {
    scanf("%d %d", &W, &V);
    item[i].first = W;   // 무게
    item[i].second = V;  // 가치
  }

  for (int i = 0; i < N; ++i) {  // 아이템 고르기
    for (int w = 0; w <= K; ++w) {
      int crt_weight = item[i].first;
      int crt_val = item[i].second;

      // 다른 것을 빼서 나를 담을 방법이 있다면
      if (w >= crt_weight) {
        dp[i][w] = dp[i][w - crt_weight] + crt_val;
      }

      // 위에서 가져올 수 있다면
      if (i > 0) {
        dp[i][w] = max(dp[i][w], dp[i - 1][w]);
      }

      // 아무것도 할 수 없으면 전역 초기화된 0으로 저장됨
    }
  }

  cout << endl;
  for (int i = 0; i < N; ++i) {  // 아이템 고르기
    for (int w = 0; w <= K; ++w) {
      printf("%3d", dp[i][w]);
    }
    cout << endl;
  }
  cout << endl;

  printf("%d\n", dp[N - 1][K]);
  return 0;
}
/*
// 입력
N K
[W V] * N

// 시간복잡도
100,000 * 100 = 1000만
*/