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