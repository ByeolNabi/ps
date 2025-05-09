//[골드2] : 트리지름
#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<pair<int, int>>;
pair<int, int> max_node = {1, 0};  // 노드, 거리 합

/* 요구사항
max dist를 갱신해나가야함 -> 갱신할 때 현재 노드도 저장해야한다.
*/
void DFS(Graph* g, bool* visited, int start, int depth) {
  // 방문 쳌
  visited[start] = true;
  // 최장 거리 저장
  if (depth > max_node.second) {
    max_node.first = start;
    max_node.second = depth;
  }
  // start에서 갈 수 있는 모든 곳으로 Dfs를 돌려본다.
  for (auto n : g[start]) {
    int node = n.first;
    int dist = n.second;
    if (!visited[n.first]) {
      DFS(g, visited, node, depth + dist);
    }
  }
}

int tree_diameter(Graph* g) {
  int crt_dist;
  int prev_dist = 0;
  while (true) {
    bool visited[100001] = {};
    DFS(g, visited, max_node.first, 0);
    crt_dist = max_node.second;
    // cout << crt_dist << " : 현 거리\n";
    if (crt_dist > prev_dist) {
      prev_dist = crt_dist;
    } else {
      break;
    }
  }

  return crt_dist;
}

int main() {
  Graph graph[100001];  // 노드 번호, 가중치

  int N, parent, child, edge;  // parent child가 아니긴 하지만...
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    scanf("%d", &parent);

    while (true) {
      scanf("%d", &child);
      if (child != -1) {
        scanf("%d", &edge);

        graph[parent].push_back({child, edge});
      } else {
        break;
      }
    }
  }

  printf("%d\n", tree_diameter(graph));
  return 0;
}

// 더 빠르게 버퍼를 받을 방법이 필요할 것 같다...?