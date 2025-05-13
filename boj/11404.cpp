// [골드4] 플로이드, dp탐색
#include <iostream>
#include <vector>

#define INF 0x3f3f3f3f
using namespace std;
using Graph = vector<vector<pair<int, int>>>;
using Edge = pair<int, int>;  // {도착 도시, 비용}

int dp[101][101];
int n, m;  // n도시, m버스노선

void floyd_warshall(Graph &g) {
  // dp field 초기화
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j)
        dp[i][j] = 0;
      else
        dp[i][j] = INF;
    }
  }

  // 초기 dp거리 설정
  for (int i = 1; i <= n; i++) {
    for (int idx = 0; idx < g[i].size(); idx++) {
      Edge crt_pair = g[i][idx];
      dp[i][crt_pair.first] = min(dp[i][crt_pair.first], crt_pair.second);
      if (dp[1][5] == 0) {
        printf("");
      }
    }
  }

  // 시작 -> k -> 목적지 (K는 거쳐갈 수 있는 모든 노드)
  for (int k = 1; k <= n; k++) {
    for (int start = 1; start <= n; start++) {  // 시작 노드
      for (int dest = 1; dest <= n; dest++) {   // 목적지 노드
        if (dp[start][k] == INF || dp[k][dest] == INF) {
          // 둘 중 하나라도 끊겨있으면 => 스킵
        } else {
          // 둘다 붙어있으면 계산해보자
          dp[start][dest] = min(dp[start][dest], dp[start][k] + dp[k][dest]);
        }
      }
    }
  }
}

int main() {
  scanf("%d %d", &n, &m);
  Graph g(n + 1);

  // 입력받기
  for (int i = 1; i <= m; ++i) {
    int idx;
    Edge tmp_pair;  // {도착 도시, 비용}
    scanf("%d %d %d", &idx, &tmp_pair.first, &tmp_pair.second);
    g[idx].push_back(tmp_pair);
  }

  floyd_warshall(g);

  // 결과 출력
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      printf("%d ", dp[i][j] == INF ? 0 : dp[i][j]);
    }
    printf("\n");
  }
  return 0;
}

/**
  // 결과 출력
  printf("\n");
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      printf("%d ", dp[i][j] == INF ? -1 : dp[i][j]);
    }
    printf("\n");
  }
  printf("\n");
 */