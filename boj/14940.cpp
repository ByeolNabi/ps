// [실버1] 쉬운 최단거리
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int board[1002][1002];  // 0으로 초기화
int visited[1002][1002];

queue<pair<int, int>> q;

// 동서남북
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
  int n, m;  // n열, m행
  scanf("%d %d", &n, &m);

  for (int row = 1; row <= n; ++row) {
    for (int col = 1; col <= m; ++col) {
      scanf("%d", &board[row][col]);
      if (board[row][col] == 1) {
        board[row][col] = -1;             // 방문하지 않은 곳
      } else if (board[row][col] == 0) {  // 벽
        continue;
      } else if (board[row][col] == 2) {
        board[row][col] = 0;  // 시작점
        q.push(make_pair(row, col));
      }
    }
  }
  // BFS

  while (!q.empty()) {
    auto now = q.front();
    q.pop();
    for (int i = 0; i < 4; ++i) {
      board[now.first + dy[i]][now.second + dx[i]];
      if (board[now.first + dy[i]][now.second + dx[i]] !=
          -1) {  // 방문한 곳이라면
        continue;
      } else {  // 첫방문이면
        board[now.first + dy[i]][now.second + dx[i]] =
            board[now.first][now.second] + 1;
        q.push(make_pair(now.first + dy[i], now.second + dx[i]));
      }
    }
  }

  string result = "";
  for (int row = 1; row <= n; ++row) {
    for (int col = 1; col <= m; ++col) {
      result.append(to_string(board[row][col])+" ");
    }
    result.append("\n");
  }

  cout << result;
}