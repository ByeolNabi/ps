#01238 다익스트라 : nodes에서 target까지의 거리
import sys
import heapq

# 다익스트라! << input: int << return: dist_result
def dijkstra(startNode, endPoint = 0):
    # 자료구조 선언부
    distances = [float('inf')] * (V+1)
    q = []
    # 다익스트라 시작 : startNode에서 시작하기 때문에 startNode의 distance를 갱신하고 heapq에 넣는다.
    distances[startNode] = 0;
    heapq.heappush(q, (distances[startNode], startNode))
    # 큐 순회공연 시작
    while q:
        c_cost, crnt = heapq.heappop(q)
        if crnt == endPoint:
            return
        else:
            # 연결된 노드의 가중치가 작아지면 방문하는 것으로 하자
            for nxt,n_cost in graph[crnt]:
                t_cost = c_cost+n_cost
                if t_cost < distances[nxt]: # 가중치가 작아지면 dist를 갱신하고 방문 후보군에 넣어두자
                    distances[nxt] = t_cost
                    heapq.heappush(q,(t_cost, nxt))
    # 큐가 비었다면 결과가 나왔다는 뜻
    return distances

input = sys.stdin.readline
# 입력부 (노드 갯수, 간선, 마을)
V, E, B = map(int, input().split())
# 자료구조 선언부
graph = [[] for _ in range(V+1)]
# 자료구조 result
beginToAll = [] # 집으로 돌아가는 값
allToBegin = [0] * (V+1) # 마을 가는 값
# 입력부
for _ in range(E):
    v1,v2,w = map(int, input().split())
    graph[v1].append((v2, w))
# 결국 모든 점에서 다익스트라를 실행 해 봐야한다.
for i in range(1,V+1):
    if i==B:    # 마을이라면
        beginToAll = dijkstra(B)
    else:
        allToBegin[i] = dijkstra(i)[B]
# 결과값 만들기
result = [-(beginToAll[i]+allToBegin[i]) for i in range(V+1)]  # 각 인덱스의 value 합하기
# float가 아닌 최댓값을 빠르게 찾기 위한 heap
heapq.heapify(result)
while result:
    weight = heapq.heappop(result)
    if weight != -float('inf'):
        break;

print(-weight)



        





'''
1. 필요한 값
    a. origin으로부터 모든 노드까지의 거리
    b. 모든 노드로부터 origin까지의 거리
    result >> 둘을 합했을 때 가장 높은 가중치를 출력한다.

🔥 생각해볼 문제
    [1.a]의 상황에서는 origin에서 다익스트라를 사용하면 된다.
    [1.b]의 상황에서는 모든 노드에서 다익스트라를 사용해야 한다.
        🤔시간복잡도가 감당할 수 있는진 모르겠다. 💡일단 탈출 코드를 넣어보자

📚 데이터 구조
    graph : 관계성 표현하기
    distances : start로부터 모든 노드까지의 최단거리
    q : 다음 노드 후보군들을 위한 힙큐

    begin to all : idx => target node, 각각의 노드에서 돌린 코드에서 begin까지의 값만 기록한다.
    all to begin : idx => begin,
'''