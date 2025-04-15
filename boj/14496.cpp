// [실버2] 14496:그대, 그머가 되어
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using Graph = vector<vector<int>>;  // 노드i에서 여러 곳에 방문할 수 있다.

vector<int> BFS(const Graph &G, int start, int end) {
  int N = G.size();
  vector<int> dist(N + 1, -1);
  queue<int> q;

  dist[start] = 0;
  q.push(start);  // 정찰병 있어요.
  while (!q.empty()) {
    int v = q.front();
    q.pop();  // 정찰병 퇴근

    bool isDst = false;

    for (auto next : G[v]) {       // v위치에서 갈 수 있는 곳 목록
      if (dist[next] == -1) {      // 첫 방문이면
        dist[next] = dist[v] + 1;  // 거리 기록하기
      }

      if (next == end) {
        isDst = true;  // 목적지까지 거리를 기록했으면 끝내도 되잖아.
        break;
      }

      q.push(next);  // 정찰병 보내기
    }
    if (isDst) break;
  }

  return dist;
}

int main() {
  int start, end, N, M;  // 시작, 끝, 문자수, 연결 갯수
  scanf("%d %d %d %d", &start, &end, &N, &M);

  Graph G(N + 1);
  int v1, v2;
  for (int i = 0; i < M; ++i) {
    scanf("%d %d", &v1, &v2);
    G[v1].push_back(v2);
    G[v2].push_back(v1);
  }

  printf("%d\n", BFS(G, start, end)[end]);

  return 0;
}