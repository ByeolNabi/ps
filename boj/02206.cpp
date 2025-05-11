// 벽 부수고 이동하기
#include <iostream>
#include <queue>
using namespace std;
using Coor = pair<int, int>;

int N, M;  // NxM 행x열;
void print_board();
void print_dist(int mode);

enum Board { BEFORE_WALL, AFTER_WALL };
char board[1002][1002];
int dist[2][1002][1002];  // [0] 보드, [1] dist, [2] wall dist
// delta 동서남북
int delta_x[] = {1, -1, 0, 0};
int delta_y[] = {0, 0, 1, -1};

int BFS() {
  // 시작점 초기 셋팅
  queue<pair<int, Coor>> q;  // dist종류, {row, col}

  q.push({BEFORE_WALL, {1, 1}});
  dist[BEFORE_WALL][1][1] = 1;

  // while 큐가 빌 때까지
  while (!q.empty()) {
    // q살펴보기
    int dist_type = q.front().first;
    Coor crt_coor = q.front().second;
    q.pop();
    // 십자 탐색
    for (int i = 0; i < 4; ++i) {
      Coor next_coor = {crt_coor.first + delta_y[i],
                        crt_coor.second + delta_x[i]};
      // 가본곳이면 가지 말자
      if (dist[dist_type][next_coor.first][next_coor.second] != 0) {
        continue;
      }

      if (dist_type == BEFORE_WALL) {
        // 길
        if (board[next_coor.first][next_coor.second] == '0') {
          q.push({BEFORE_WALL, {next_coor.first, next_coor.second}});
          dist[BEFORE_WALL][next_coor.first][next_coor.second] =
              dist[BEFORE_WALL][crt_coor.first][crt_coor.second] +
              1;  // 거리 기록
        }
        // 벽
        else if (board[next_coor.first][next_coor.second] == '1') {
          if (dist[AFTER_WALL][next_coor.first][next_coor.second] != 0) {
            continue;  // 벽을 부수지만 그 값이 이미 갱신되어 있다면 덮어씌우지
                       // 말 것
          }
          q.push({AFTER_WALL, {next_coor.first, next_coor.second}});
          dist[AFTER_WALL][next_coor.first][next_coor.second] =
              dist[BEFORE_WALL][crt_coor.first][crt_coor.second] + 1;
        }
        // 장외
        else if (board[next_coor.first][next_coor.second] == -1) {
          // 넘어가기
        }
      } else if (dist_type == AFTER_WALL) {
        // 길
        if (board[next_coor.first][next_coor.second] == '0') {
          q.push({AFTER_WALL, {next_coor.first, next_coor.second}});
          dist[AFTER_WALL][next_coor.first][next_coor.second] =
              dist[AFTER_WALL][crt_coor.first][crt_coor.second] +
              1;  // 거리 기록
        }
        // 장외
        else if (board[next_coor.first][next_coor.second] == -1) {
          // 넘어가기
        }
      }
    }
  }

  return 1;
}

int main() {
  scanf("%d %d", &N, &M);
  for (int row = 1; row <= N; ++row) {
    scanf("%s", &board[row][1]);
  }
  // 테두리 설정
  for (auto row : {0, N + 1}) {
    for (int i = 0; i <= M + 1; ++i) {
      board[row][i] = -1;
    }
  }
  for (auto col : {0, M + 1}) {
    for (int i = 0; i <= N + 1; ++i) {
      board[i][col] = -1;
    }
  }

  BFS();
  // print_board();
  // print_dist(BEFORE_WALL);
  // print_dist(AFTER_WALL);

  // 벽 부순 후 dist가 0이면 -> 벽 x dist가 0이면 -> 도달 못 함
  printf("%d\n",
         (dist[AFTER_WALL][N][M] != 0)
             ? dist[AFTER_WALL][N][M]
             : ((dist[BEFORE_WALL][N][M] != 0) ? dist[BEFORE_WALL][N][M] : -1));

  return 0;
}
/*
7 6
010000
010010
010010
000010
000010
000010
000010
*/

void print_board() {
  for (int row = 0; row <= N + 1; ++row) {
    for (int col = 0; col <= M + 1; ++col) {
      printf("%2d ", board[row][col]);
    }
    printf("\n");
  }
  printf("\n");
}

void print_dist(int mode) {
  if (mode == BEFORE_WALL) {
    // 벽 안 부수기 탐색
    for (int row = 0; row <= N + 1; ++row) {
      for (int col = 0; col <= M + 1; ++col) {
        printf("%2d ", dist[BEFORE_WALL][row][col]);
      }
      printf("\n");
    }
    printf("\n");

  } else if (mode == AFTER_WALL) {
    // 벽 부순 후 탐색
    for (int row = 0; row <= N + 1; ++row) {
      for (int col = 0; col <= M + 1; ++col) {
        printf("%2d ", dist[AFTER_WALL][row][col]);
      }
      printf("\n");
    }
    printf("\n");
  }
}