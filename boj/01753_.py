#01238 다익스트라 기본
import sys
import heapq # 우선순위 큐

INF = int(300000)
input = sys.stdin.readline
# start로부터의 거리 반환, 관계성은 기록하지 않음
def dijkstra(graph, start):
    # 최단거리 저장을 위한 표
    distance = {node: INF for node in graph}
    # 초기 설정 (start가 시작 지점일 때)
    distance[start] = 0;
    queue = []
    heapq.heappush(queue, [distance[start], start])
    # 반복
    while queue:
        # 일단 현재 위치를 뽑자
        current_distance, current_destination = heapq.heappop(queue);   
        # 갱신되는 숫자보다 힙에 저장된 숫자가 크다면 무시해야 한다. >> 최단거리가 아니기 때문
        if distance[current_destination] < current_distance:
            continue
        # 현재 위치에서 관계를 가진 모든 노드를 순환한다.
        for new_destination, new_distance in graph[current_destination].items():
            # 현재 위치로부터 다음 노드까지의 누적 거리를 구해본다.
            sum_distance = current_distance + new_distance
            # 더 짧은 길을 발견했다면 거리를 업데이트 한다.
            if sum_distance < distance[new_destination]:
                distance[new_destination] = sum_distance
                # 짧은 길을 발견했다면 큐에 넣는다. >> 그 노드로 가는 최단거리이기 때문이다.
                    # 짧은 길을 발견했다고 큐를 넣으면 모든 노드를 한 번씩 넣을 수 있게 되는 건가?
                heapq.heappush(queue, [sum_distance, new_destination])
    
    return distance;
    
# 입력 받기
n_num, e_num = map(int, input().split())
start_node = int(input())
# 관계성을 기록한 graph 만들기
graph = {i:{} for i in range(1,n_num+1)}
for i in range(e_num):
    start, end, weight = map(int,input().split())
    graph[start][end] = weight
    
dist = dijkstra(graph, start_node);
for w in dist:
    if dist[w] == INF:
        print("INF")
    else:
        print(dist[w])

"""
5 9
1
1 2 6
1 3 2
1 4 10
2 4 3
2 5 4
3 2 3
3 5 4
4 3 4
5 4 1
"""
#### 메모리 초과 ####
# 메모리 초과면 저장하는 방법을 변경해야 할 것 같은데...
# 힙과 dictionary를 사용하자
# def fail_1():
#     #입력 받기
#     node_nums, edges_nums = map(int, input().split())
#     start = int(input())
#     # 그래프 테이블 [start][end]
#     table = [[-1 for col in range(node_nums+1)] for row in range(node_nums+1)]
#     # 최단거리 계산을 위한 테이블
#     earlier = [-1]*(node_nums+1)
#     distance = [101]*(node_nums+1)
#     visited = [0]*(node_nums+1)   # 낮은 값으로 갱신해줘야 하기 때문에 조건의 max+1로 초기화

#     # 그래프 가중치 테이블 만들기
#     for case in range(edges_nums):
#         # start, end, weight
#         s, e, w = map(int, input().split())
#         table[s][e] = w

#     # 테이블을 이용해서 최단거리 찾기
#     # 일단 다익스트라 기본 템플릿 만들기
#     current = start
#     # 노드의 갯수만큼 방문하기
#     for i in range(1,node_nums+1):
#         # 첫 방문이라면 start으로 초기화해야지
#         if(i == 1):
#             # 시작점으로 표 초기화하기
#             earlier[current] = start;
#             distance[current] = 0;
#         visited[current] = 1;
#         # 현재 위치에서 짧은 거리로 갱신하기
#         for next in range(1,node_nums+1):
#             # 방문하지 않았고, 현재 위치로부터 next까지의 거리가 더 짧다면 >> e, d 갱신하기
#             if visited[next] == 0 and table[current][next] != -1 and (distance[current]+table[current][next] < distance[next]):
#                 distance[next] = distance[current]+table[current][next]
#                 earlier[next] = current

#         def min_num(old, new):
#             return old if old < new else new;
#         # 거리가 가장 짧은 곳으로 간다
#         nearest = float('inf')
#         for j in range(1,node_nums+1):
#             # 방문하지 않았다면
#             if visited[j] == 0:
#                 # 거리가 짧다면 갱신 + 다음 목적지도 갱신하기
#                 if nearest > distance[j]:
#                     nearest = distance[j];
#                     current = j;

#     for i in distance[1:]:
#         print(i if i!=101 else "INF")