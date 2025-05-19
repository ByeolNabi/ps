//[골드3] 웜홀
#include <iostream>
#include <vector>
using namespace std;

#define INF 0x3f3f3f3f

using Node = pair<int, int>;  // 목적지, 비용
using Graph = vector<Node>;

int main() {
  int TC;
  scanf("%d", &TC);
  while (TC--) {
    Graph g[501];

    int N, M, W;  // 지점 갯수, 도로, 웜홀
    scanf("%d %d %d", &N, &M, &W);

    int S, E, T;  // 지점1, 지점2, 비용
    // 도로 양방향
    for (int i = 0; i < M; i++) {
      scanf("%d %d %d", &S, &E, &T);
      g[S].push_back({E, T});
      g[E].push_back({S, T});
    }
    // 웜홀 단방향
    for (int i = 0; i < W; i++) {
      scanf("%d %d %d", &S, &E, &T);
      g[S].push_back({E, -T});
    }
    // 모든 노드와 연결된 새로운 노드
    for (int i = 1; i <= N; ++i) {
      g[0].push_back({i, 0});
    }

    // 벨만 포드
    int dist[501];
    for (int i = 0; i <= N; ++i) {
      dist[i] = INF;
    }

    dist[0] = 0;                     // 시작하는 곳 0으로 지정하기
    for (int i = 0; i < N; ++i) {    // 노드갯수 -1 번 반복
      for (int i = 0; i <= N; ++i) {  // 모든 노드 순회
        // i에서 갈 수 있는 다음 노드 탐색
        for (auto edge : g[i]) {
          // 나 거쳐서 다음 까지 거리 < 다음 까지 거리 => 갱신하기
          if (dist[i] != INF && dist[i] + edge.second < dist[edge.first]) {
            dist[edge.first] = dist[i] + edge.second;
          }
        }
      }
    }

    // 모든 노드 체크 완료 후 완화가 일어나는지 확인
    bool release = false;
    for (int i = 0; i <= N; ++i) {
      // i에서 갈 수 있는 다음 노드 탐색
      for (auto edge : g[i]) {
        // 나 거쳐서 다음 까지 거리 < 다음 까지 거리 => 갱신하기
        if (dist[i] != INF && dist[i] + edge.second < dist[edge.first]) {
          release = true;
          break;
        }
      }
    }
    printf("%s\n", release ? "YES" : "NO");
  }
  return 0;
}

// 3 3 1
// 두 번째 줄부터 M+1 => 2 ~ 3+1
// M+2번째 줄부터 M+W+1번째 줄까지 웜홀의 정보 => 3+2 => 3+1+1

// https://www.acmicpc.net/board/view/72995

// 벨만-포드 (VE)
// 플로이드 (V^3)

// 음의 사이클 찾기? 음의 사이클 찾기!