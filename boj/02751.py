# fast I/O
import sys
input=sys.stdin.readline
import heapq

q=[]
tc = int(input())
for i in range(tc):
    heapq.heappush(q,int(input()))

while q:
    print(heapq.heappop(q))