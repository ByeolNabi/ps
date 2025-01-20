# DFS BFS
from collections import deque


def dfs(graph, start, visited):
    visited[start] = True
    result.append(start)
    for next in graph[start]:
        if not visited[next]:
            dfs(graph, next, visited)


def bfs(graph, start):
    visited = [False] * (n + 1)
    result = []
    visited[start] = True
    queue = deque([start])  # 여기서 시작

    while queue:  # 큐 다 빠질때까지 방문하기
        start = queue.popleft()  # 큐 방문 완료.
        result.append(start)
        for next in graph[start]:  # 후보 대기열에 넣을 후보 순환하기
            if not visited[next]:
                queue.append(next)  # 대기열에 들어갈 수 있습니다.
                visited[next] = True   # 무조건 방문할 예정이니 방문했다고 할게요

    return result
# bfs는 방문한다와 방문할거다의 괴리감이 좀 있다.


n, m, v = map(int, input().split())  # 노드갯수, 간선갯수, 시작지점
graph = [[] for _ in range(n + 1)]  # 문법 좀 더 찾아보기

for i in range(m):
    start, next = map(int, input().split())  # 입력 받기
    graph[start].append(next)  # graph 만들기, start에 next값 저장하기
    graph[next].append(start)   # 양방향그래프였고

for nodes in graph:  # 작은 것 먼저 방문하라고 했으니 소팅하기
    nodes.sort()  # 오름차순

# DFS
result = []  # 방문순서 저장
visited = [False] * (n + 1)
dfs(graph, v, visited)
print(" ".join(map(str, result)))

# BFS
print(" ".join(map(str, bfs(graph, v))))
