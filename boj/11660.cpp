#include <iostream>
using namespace std;

int mat[1025][1025];
long long dp[1025][1025];

int main() {
  int N, M;  // N*N mat, M만큼의 tc;
  scanf("%d %d", &N, &M);
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      scanf("%d", &mat[i][j]);
      dp[i][j] = mat[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
    }
  }

//   for (int i = 0; i <= N; i++) {
//     for (int j = 0; j <= N; j++) {
//       printf("%lld ", dp[i][j]);
//     }
//     printf("\n");
//   }
//   printf("\n");

  for (int i = 0; i < M; ++i) {
    int p1[2], p2[2];  // {x, y} <= 전통적인 가로축 x가 아니라 x행 y열이라고 한다...

    scanf("%d %d %d %d", &p1[0], &p1[1], &p2[0], &p2[1]);
    long long area_topleft, area_top, area_left, area_me;
    area_topleft = dp[p1[0] - 1][p1[1] - 1];
    area_top = dp[p2[0]][p1[1] - 1];
    area_left = dp[p1[0] - 1][p2[1]];
    area_me = dp[p2[0]][p2[1]];
    // printf("%lld %lld\n", area_topleft, area_top);
    // printf("%lld %lld\n", area_left, area_me);

    long long result = area_me - area_top - area_left + area_topleft;
    printf("%lld\n", result);
  }

  return 0;
}