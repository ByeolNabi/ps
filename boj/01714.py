# 골드4 : 우선순위큐
import heapq
import sys
input = sys.stdin.readline

# 입력부
cases = int(input())
q = []
heapq.heappush(q, float('inf')) # 마지막 토큰

for i in range(cases):
    heapq.heappush(q, int(input()))   # 최소 힙

total = 0;
if cases == 1:
    print(0)
else:
    while q:
        n1 = heapq.heappop(q)
        n2 = heapq.heappop(q)
        if n2 == float('inf'):
            print(total)
        else:
            s = n1+n2
            heapq.heappush(q, n1+n2)
            total += s

'''
정렬된 카드가 한 개만 들어오면 이미 정렬되어있기 떄문에 0을 출력해야 한다.
'''