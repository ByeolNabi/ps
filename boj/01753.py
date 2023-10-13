#01753 다익스트라 기본
import sys
import heapq

input = sys.stdin.readline
INF = int(300000)

# 입력
V, E = map(int, input().split())
s_node = int(input())

graph = [[]for _ in range(V+1)]
distance = [INF] * (V+1)

# graph 만들기
for _ in range(E):
    v1, v2, w = map(int, input().split())
    graph[v1].append((v2, w))

def dijkstra():
    
# distance를 계산해서 반환해줌
dijkstra(s_node)

for i in distance:
    print("INF" if i == INF else i);