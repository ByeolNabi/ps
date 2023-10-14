#01238 다익스트라 기본

#입력 받기
node_nums, edges_nums = map(int, input().split())
start = int(input())
# 그래프 테이블 [start][end]
table = [[-1 for col in range(node_nums+1)] for row in range(node_nums+1)]
# 최단거리 계산을 위한 테이블
earlier = [-1]*(node_nums+1)
distance = [101]*(node_nums+1)
visited = [0]*(node_nums+1)   # 낮을 값으로 갱신해줘야 하기 때문에 조건의 max+1로 초기화

# 그래프 가중치 테이블 만들기
for case in range(edges_nums):
    # start, end, weight
    s, e, w = map(int, input().split())
    table[s][e] = w

# 테이블을 이용해서 최단거리 찾기
# 일단 다익스트라 기본 템플릿 만들기
current = start
# 노드의 갯수만큼 방문하기
for i in range(1,node_nums+1):
    # 첫 방문이라면 start으로 초기화해야지
    if(i == 1):
        # 시작점으로 표 초기화하기
        earlier[current] = start;
        distance[current] = 0;
    visited[current] = 1;
    # 현재 위치에서 짧은 거리로 갱신하기
    for next in range(1,node_nums+1):
        # 방문하지 않았고, 현재 위치로부터 next까지의 거리가 더 짧다면 >> e, d 갱신하기
        if visited[next] == 0 and table[current][next] != -1 and (distance[current]+table[current][next] < distance[next]):
            distance[next] = distance[current]+table[current][next]
            earlier[next] = current

    def min_num(old, new):
        return old if old < new else new;
    # 거리가 가장 짧은 곳으로 간다
    nearest = float('inf')
    for j in range(1,node_nums+1):
        # 방문하지 않았다면
        if visited[j] == 0:
            # 거리가 짧다면 갱신 + 다음 목적지도 갱신하기
            if nearest > distance[j]:
                nearest = distance[j];
                current = j;

for i in distance[1:]:
    print(i if i!=101 else "INF")

#### ========================================= ####
import sys
import heapq

input = sys.stdin.readline
INF = int(1e9)
def dijkstra(start):
    q= []
    heapq.heappush(q,(0,start))
    distance[start] = 0

    while q:
        dist, now = heapq.heappop(q)

        if distance[now] < dist:
            continue

        #현재 노드와 연결된 인접 노드 확인
        for i in graph[now]:
            cost =dist+ i[1]
            if cost < distance[i[0]] :
                distance[i[0]] = cost
                heapq.heappush(q,(cost,i[0]))


#V == 5일 때 1~5까지 노드가 있는거임.
V, E = map(int,input().split())

s_node = int(input()) #시작 노드

graph = [[] for _ in range(V+1)]
distance = [INF] * (V+1) #최단 거리 테이블
#연결 정보 입력
for _ in range(E):
    u,v,w = map(int,input().split())
    graph[u].append((v,w))

dijkstra(s_node)

#i번째 줄에 i번 정점으로의 최단 경로의 경로값을 출력
for i in range(1,V+1):
    if distance[i] == INF:
        print("INF")
    else:
        print(distance[i])

"""
import sys
import heapq

V, E, START

# 자료구조
graph : 인덱스 마다 >> (연결 노드:비용)
distances : 인덱스마다 최소비용 저장 << 최종 결과물이 저장 될 곳, inf로 초기화한다.
q : 후보 노드 저장을 위한 최소힙 >> (w of start to node_name, node_name)


##### 알고리즘 #####
def dijk(START):
    # 초기 설정
    ## 일단 START를 힙에 넣는다, distances를 초기화한다.
    heapq.heappush(q, (0, START))
    distances[START]를 0으로
    # 힙이 다 없어질 때 까지 >> 힙과 조건을 활용해서 visited를 이용하지 않아도 된다.
    while q:
        total_weight, crnt = 힙.pop
        #crnt노드와 연결성이 존재하는 모든 노드를 일단 탐색한다.
        for candidate in graph[crnt노드와 연결된 노드의 집합]:
            w of start to candidate
            if w < distance[candidate]:
                distance[candidate] = cost
                heapq.heappush(q, (cost, candidate))
                
                



🔥참고사항 : 딕셔너리가 만능이 아니다. 노드의 이름과 index를 매칭할 수 있다면 그게 결국 dictionary형태이다 O(1).
>> 간선 사이에 두 개 이상의 가중치가 있을 수 있으니 list에 append를 시키는 편이 안전하다.
"""