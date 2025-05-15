#include <iostream>
#include <vector>
using namespace std;

using Graph = vector<int>;

int idx(char c) { return c - 'A'; }  // ascii의 A가 0이 되게 하는
string pre = "";
string in = "";
string post = "";

void DFS(Graph* g, int c) {
  if (c == '.' - 'A') {
    return;
  }
  pre += c + 'A';
  DFS(g, g[c][0]);
  in += c + 'A';
  DFS(g, g[c][1]);
  post += c + 'A';
}

int main() {
  int N;
  scanf("%d ", &N);
  Graph g[26];

  for (int i = 0; i < N; ++i) {
    char top, child1, child2;
    cin >> top >> child1 >> child2;
    // cout << top << ":" << child1 << ":" << child2 << endl;
    g[idx(top)].push_back(idx(child1));
    g[idx(top)].push_back(idx(child2));
  }
  DFS(g, idx('A'));

  printf("%s\n%s\n%s\n", pre.c_str(), in.c_str(), post.c_str());
  return 0;
}