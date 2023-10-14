#01753 다익스트라 기본
import sys
import heapq

input = sys.stdin.readline
INF = int(30000000)

# 입력
V, E = map(int, input().split())
s_node = int(input())

# 자료구조 (편의를 위해 인덱스 0을 비워두자)
graph = [[]for _ in range(V+1)]
distances = [INF] * (V+1)
q=[]

# graph 만들기
for _ in range(E):
    v1, v2, w = map(int, input().split())
    graph[v1].append((v2, w)) # (목적지, 가중치)

def dijkstra(start):
    # 총 비용, 노드
    heapq.heappush(q, (0, start)) # 힙에 넣는 행위를 후보를 찾는 것이다. >> 아직 방문한 것이 아니다.
    distances[start] = 0;
    # 더 이상 다음으로 갈 곳이 없을 때 (힙이 비었을 때)
    while q:
        dist, now = heapq.heappop(q) # 힙에 있는 후보중 가장 가까운 곳을 본다.
        # 다음 노선이 짧아지는 길이 아니라면 무시한다.
        if distances[now] < dist:
            continue;
        # 짧아지는 길이라면 now노드에 방문한다. 현재 노드에서 더 짧은 비용으로 갈 수 있는 길을 찾는다면 갱신시키고 힙에 넣는다.
        for n_node in graph[now]:
            cost = dist+n_node[1]; # start to now + now to next
            if cost < distances[n_node[0]]: # 짧은 길을 찾았다면
                distances[n_node[0]] = cost # 갱신하기
                heapq.heappush(q,(cost, n_node[0])) # 갱신했다면 최단거리 후보로써 힙에 저장한다.
    
# distance를 계산해서 반환해줌
dijkstra(s_node)

for i in distances[1:]:
    print("INF" if i == INF else i);

# 자료구조
# graph : 노드의 관계성을 저장 (목적지, now to next weight)
# dist : 최단거리를 저장해 나갈 곳
# heap : 다음 목적지를 저장할 최소힙 (dist of start to next, next-node)