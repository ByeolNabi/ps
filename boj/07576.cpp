// [골드5] 토마토
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using Node = pair<int, int>;  // make_pair(row,col);
using Graph = vector<vector<int>>;

int tomato;
// 동서남북 Delta
const int delta_x[4] = {1, -1, 0, 0};
const int delta_y[4] = {0, 0, -1, 1};

void chmax(int &origin, int new_val) {
  if (origin < new_val) {
    origin = new_val;
  }
}

void printG(const Graph &G) {
  for (auto row : G) {
    for (auto col : row) {
      printf("%4d", col);
    }
    cout << endl;
  }
  cout << endl;
}

int BFS(Graph &G, Graph &dist, const vector<Node> &start) {
  queue<Node> q;
  int max = 0;
  int rotten_tomato = 0;  // 익힌 토마토 (안 익힌 -> 익힌)

  for (const Node n : start) {  // 시작점 q에 넣기
    q.push(n);                  // 정찰병
    dist[n.first][n.second] = 0;
  }

  while (!q.empty()) {
    Node n = q.front();
    q.pop();
    int crt_dist = dist[n.first][n.second];

    for (auto d : {0, 1, 2, 3}) {  // 동,서,남,북
      if (dist[n.first + delta_y[d]][n.second + delta_x[d]] != -1) {
        continue;
        // 이미 거리를 잰 곳이면 스킵
        // (? 그럼 시작 지점을 방문 안 한걸로 생각하고가는거 아냐?)
        // => 안 가본 곳은 -1, 테두리를 0으로 해놔도 가본 곳으로 치기 때문에
        // 방문 안 함
      }

      // 방문 프로세스
      q.push(make_pair(n.first + delta_y[d], n.second + delta_x[d]));
      dist[n.first + delta_y[d]][n.second + delta_x[d]] =
          crt_dist + 1;  // 이전보다 1칸 멀어
      ++rotten_tomato;

      chmax(max, crt_dist + 1);
      // printG(dist);
    }
  }

  if (rotten_tomato != tomato) max = -1;  // 덜 익은 토마토가 있다면 -1 출력

  return max;
}

int main() {
  int M, N;  // 가로칸(열갯수), 세로칸(행갯수) 사이즈 2~1000 >> 최악 1,000,000
  scanf("%d %d", &N, &M);
  Graph G(M + 2, vector<int>(N + 2, 0));
  Graph dist = G;
  vector<Node> start;

  int tmp;

  for (int row = 0; row < M; ++row) {
    for (int col = 0; col < N; ++col) {
      scanf("%d", &tmp);
      if (tmp == 1) {  // 익은 토마토면 시작점에 넣는다.
        start.push_back(make_pair(row + 1, col + 1));
        dist[row + 1][col + 1] = -1;  // 안 가본 곳이라고 기록한다.
      } else if (tmp == 0) {          // 덜 익은 토마토
        ++tomato;                     // 익혀야 하는 토마토 갯수, 0의 갯수
        dist[row + 1][col + 1] = -1;  // 안 가본 곳이라고 기록한다.
      } else if (tmp == -1) {
        dist[row + 1][col + 1] = 0;  // 가본 곳
      }
      G[row + 1][col + 1] = tmp;  // 표에 입력받은 값을 저장한다.
    }
  }

  printf("%d", tomato == 0 ? 0
                           : BFS(G, dist,
                                 start));  // 익혀야하는 토마토가 0개이면 0 출력

  return 0;
}

// 1. 토마토가 2개 이상일때, 첫 토마토로부터 다 익혀보고 다음 토마토에서 다 익힌
// 다음, 최댓값을 찾을지
// 2. 토마토 2개를 queue에 넣어두고, 그냥 돌려볼지
// (1)은 불필요한 연산을 한다, (2)bfs특성상 두개를 queue에 넣어도 불편할게 없다.
// 테투리가 있는 것을 염두에 두고 어떻게 방문했다를 판단할것인가
// 0이면 아직 방문 안 함. 테두리를 -1으로 설정함

// 토마도 다 안 익었을때도 고려해야한다.