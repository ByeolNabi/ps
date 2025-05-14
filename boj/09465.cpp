// [실버1] 스티커 // 아마도 2중 최댓값 개구리 점프...?
#include <iostream>
using namespace std;

int board[2][100001];
int n;

int DFS(int r, int c, int mem[][100001]) {
  if (c < 0) {
    return 0;
  }

  if (mem[r][c] == 0) {  // 계산 x => 탐색
    mem[r][c] = max(DFS(r ? 0 : 1, c - 1, mem), DFS(r ? 0 : 1, c - 2, mem)) +
                board[r][c];

    // for (int i = 0; i < 2; i++) {
    //   for (int j = 0; j < n; j++) {
    //     printf("%d ", mem[i][j]);
    //   }
    //   printf("\n");
    // }
    // printf("\n");

    return mem[r][c];
  } else {  // 계산 o => 로드
    return mem[r][c];
  }
}

int main() {
  int tc;  // 테케, n열 스티커
  scanf("%d", &tc);
  while (tc--) {
    int mem[2][100001] = {};

    scanf("%d", &n);
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < n; j++) {
        scanf("%d", &board[i][j]);
      }
    }
    mem[0][0] = board[0][0];
    mem[1][0] = board[1][0];

    printf("%d\n", max(DFS(0, n - 1, mem), DFS(1, n - 1, mem)));
  }
  return 0;
}