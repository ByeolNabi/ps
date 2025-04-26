// [실버2] 연결 요소의 개수
#include <iostream>
using namespace std;

int linked[1000];

int find(int n) {        // 탑노드 찾기
  if (linked[n] == n) {  // 탑노드라면 탑노드 숫자 리턴
    return n;
  }
  return find(linked[n]);  // 탑노드가 아니라면 나의 부모 노드 리턴
}

void unite(int n1, int n2) {
  // v1. 앞 노드의 대장님에게 뒷 노드를 붙여주자 // issue. 뒷 노드가 이미 다른
  // 대장이 있을 때, 대장을 버리고 앞 노드의 대장에게 붙음 v2. 새로운 노드를
  // 이미 존재하는 대장 노드에 붙여주자(간선은 단 한번만 생성된다고 했음으로)
  // v2-1. 두 노드의 최상위 노드들을 어찌 어찌 연결해주자
  linked[find(n1)] = find(n2); // n2노드의 대장 노드에 n1노드의 대장 노드를 부하로 넣자.
  return;
};

int main() {
  int M, N;
  cin >> M >> N;

  for (int idx = 1; idx <= M; ++idx) {  // 나는 나를 가리키게 하자.
    linked[idx] = idx;
  }

  int n1, n2;
  for (int i = 0; i < N; ++i) {
    cin >> n1 >> n2;
    unite(n1, n2);
  }

  int result = 0;
  for (int i = 1; i <= M; ++i) {
    if (linked[i] == i) {  // 내 윗사람이 나밖에 없으면 그것이 탑 노드(유니언)
      ++result;
    }
  }
  printf("%d\n", result);
  return 0;
}
/*
8 5
1 3
2 3
4 5
7 5
8 5
*/