// N과 M(2)
#include <iostream>
#include <queue>
using namespace std;

int board[9][9];
std::vector<int> stk;

void BFS(int start_node, int depth, int N) {  // start부터 골라야하는 숫자
  if (depth == 0) {
    for (auto& val : stk) {
      printf("%d ", val);
    }
    printf("\n");
    return;
  }
  for (int i = start_node; i <= N - (depth - 1); ++i) {
    stk.push_back(i);
    BFS(i + 1, depth - 1, N);
    stk.pop_back();
  }
}

int main() {
  int N, M;  // N까지 자연수, M개 수열
  cin >> N >> M;

  BFS(1, M, N);
  return 0;
}