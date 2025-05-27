// [골드4] 최소 스패닝 트리
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Edge {
  int to_;
  int weight_;

  bool operator>(const Edge& child) const {
    return this->weight_ > child.weight_;
  }  // 참이면 스왑
};

int main() {
  int V, E;
  cin >> V >> E;
  vector<vector<Edge>> g(V + 1);

  int A, B, C;  // A정점, B정점, C가중치
  for (int i = 0; i < E; i++) {
    scanf("%d %d %d", &A, &B, &C);
    g[A].push_back({B, C});
    g[B].push_back({A, C});
  }

  /* init */
  // 작은 값이 pop되어야하기 때문에 greater를 사용한다.
  priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
  vector<bool> visited(V + 1);

  // 시작점 입력
  pq.push({1, 0});

  int MST_weight = 0;
  while (!pq.empty()) {
    // 현재 노드에서 가장 가까운 곳 점령하기
    Edge crt_edge = pq.top();
    int crt_node = crt_edge.to_;
    int crt_weight = crt_edge.weight_;
    pq.pop();

    if (visited[crt_node]) { // ㅂ
      continue;
    }
    // 점령한 노드는 방문한거임
    visited[crt_node] = true;
    // 가중치 더해야함
    MST_weight += crt_weight;
    // cout << crt_node << " : " << crt_weight << endl;

    // 점령한 노드에서 안 가본 노드에 대한 간선 모두 탐색
    for (Edge& next_edge : g[crt_node]) {
      int next_node = next_edge.to_;
      // 방문 했었으면 스킵
      if (visited[next_node]) {
        continue;
      }
      // 방문 안 했으면 queue에 넣기
      pq.push(next_edge);
    }
  }

  cout << MST_weight << '\n';
  visited[0];

  return 0;
}