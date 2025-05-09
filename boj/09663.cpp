// [골드4]N-Queen
#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> queen_coors;
int board[17][17] = {};
int cnt = 0;

// 10, 12, 2시 방향 탐색
bool isQueen(int row, int col) {
  for (auto coor : queen_coors) {
    if (col == coor.second) {
      return true;
    } else if (abs((1. * row - coor.first) / (1. * col - coor.second)) == 1) {
      return true;
    }
  }
  return false;
}

void DFS(int row, int size) {
  if (row > size) return;
  for (int i = 1; i <= size; ++i) {
    if (isQueen(row, i)) continue;
    if (row == size) ++cnt;

    queen_coors.push_back({row, i});
    DFS(row + 1, size);
    queen_coors.pop_back();
  }
}

int main() {
  int N;
  scanf("%d", &N);
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= N; ++j) {
      board[i][j] = 1;  // 사용 가능한 board초기화
    }
  }

  DFS(1, N);
  printf("%d", cnt);

  return 0;
}

/*
퀸을 일단 배치한 후 8방향으로 서치를 해보고 다른 퀸이 없으면 배치한다.
위에서부터 퀸을 배치할 것이기 때문에 좌우, 아래 방향은 서치할 필요가 없다.
10 12 2 방향만 서치하자.
*/