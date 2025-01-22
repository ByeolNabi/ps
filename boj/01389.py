# [실버1]케빈 베이컨의 6단계 법칙
import math


def floyd_warshall(n, dist):
    for k in range(n):
        for i in range(n):
            for j in range(n):
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
    pass


N, M = map(int, input().split())  # 유저의 수 N, 친구 관계의 수 M

dist = [[math.inf] * N for _ in range(N)]
for i in range(N):
    dist[i][i] = 0

for _ in range(M):
    nodeA, nodeB = map(int, input().split())
    dist[nodeA - 1][nodeB - 1] = 1
    dist[nodeB - 1][nodeA - 1] = 1

floyd_warshall(N, dist)

result = [0] * N
for i in range(N):
    result[i] = sum(dist[i])

minimum = result.index(min(result))
print(minimum+1)
