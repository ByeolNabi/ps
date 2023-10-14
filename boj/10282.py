#10282 다익스트라
import sys
import heapq



input = sys.stdin.readline
INF = float("inf");
# tc 만큼 반복
tc = int(input())
for c in range(tc):
    # 입력부 V:vertex, E:edge, B:begining
    V, E, B = map(int, input().split())
    # 자료구조 만들기
    graph = [[] for _ in range(V+1)]
    distances = [float('inf') for _ in range(V+1)]
    q = []
    # 관계성 graph 만들기
    for _ in range(E):
        v2, v1, w = map(int, input().split())
        graph[v1].append((v2, w)) # v1에서 갈 수 있는 곳 >> (v2노드 : 가중치)
        
    # 다익스트라
    def dijkstra(b_node):
        # init
        distances[b_node] = 0;
        heapq.heappush(q, (0, b_node)) # (거리, 노드)
        # 큐 순회
        while q:
            d, crnt = heapq.heappop(q)
            # 인접한 모든 노드 중 갱신 가능한 것이 있는지 판단.
            for next in graph[crnt]: # next==(노드, 가중치)
                if d+next[1] < distances[next[0]]:
                    # 갱신하기
                    distances[next[0]] = d+next[1]
                    # 힙에 넣기
                    heapq.heappush(q,(distances[next[0]], next[0]))
    
    dijkstra(B)
    # 정상적인 가중치 중에서 가장 큰 값을 가진 노드를 찾아야 한다.
    cnt = 0
    max_num = 0
    for dist in distances:
        if dist!=float('inf'):
            cnt += 1
            if max_num < dist:
                max_num = dist
    # 출력부
    print(cnt,max_num)


