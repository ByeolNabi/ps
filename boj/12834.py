#12834 다익스트라
import heapq
import sys
input = sys.stdin.readline

# 입력부
N, V, E = map(int, input().split())
kist, ssial = map(int, input().split())
N_locs = list(map(int, input().split()))
graph = [[] for _ in range(V+1)] # 그래프 초기 설정
# 관계성 그래프 만들기
for i in range(E):
    v1, v2, w = map(int, input().split())
    graph[v1].append([w,v2])
    graph[v2].append([w,v1])

# 모든 night로부터 (nignt<=>KIST + night<=>씨알푸드)를 구해야한다.
total = 0;
for N_loc in N_locs:
    def dijkstra():
        # 순회 하기 전 자료구조 선언
        q = [] # 힙큐
        distance = [float('inf')]*(V+1)
        # 초기값 넣기
        distance[N_loc] = 0
        heapq.heappush(q, [0, N_loc]) # 다음에 갈 후보지
        # 큐 순회 시작 
        while q:
            # 다음 후보지를 함 보자~
            crt_d, crt_n = heapq.heappop(q)
            # 이 후보지로 가면 이득이야? // 값이 같거나 작으면 그 곳으로 가자, 값이 작을 때만 확정짓는다면 저번 for문에서 이미 갱신된 값이 있기 떄문에 절대로 최솟값을 확정짓지 않을 것이다.
            if crt_d<=distance[crt_n]: # 후보지로 가는 방법이 저번에 갔던 방법보다 빠른 길이라면 가자
                # distance[crt_n] = crt_d # 빠른 길이라면 갱신해~ // 갱신은 이미 되어있을 것이다.
                # 현재 위치에서 갈 수 있는 모든 노드 후보군을 보고 길이가 더 짧은 방법이라면 큐에 넣자
                for nxt_d, nxt_n in graph[crt_n]: # 다음 노드로 가기위한 가중치
                    if crt_d + nxt_d < distance[nxt_n]: # 갱신 가능하면
                        distance[nxt_n] = crt_d + nxt_d # 갱신해, 갱신했다면?
                        heapq.heappush(q, [distance[nxt_n], nxt_n]) # 힙에 넣어

        return -1 if distance[kist] == float('inf') else distance[kist], \
            -1 if distance[ssial] == float('inf') else distance[ssial] # 도착하지 못 했다면 -1을 출력하기 위한 조건문
    toKIST, toSsial = dijkstra()
    total += toKIST + toSsial

print(total)

'''
💁‍♂️ 문제 설명
    기사단 N명, 노드 수 V개, 간선 수 E개
    한 사람의 거리 d = (집, KIST) 최단거리 + (집, 씨알푸드) 최단거리
        exception) 도달할 수 없다면 최단거리를 -1로 정의한다.

🎯 입출력
    기사단의 수 N , 노드의 수 V, 도로의 수 E
    KIST 위치의 번호 A, 씨알푸드의 번호 B
    기사단이 사는 번호 N개가 일렬로 입력된다.
    노드A <-> 노드B : 사잇 거리
    
🔥 알고리즘
    각각의 기사단 위치에서 다익스트라를 실행해서 KIST, 씨알푸드 까지의 거리를 각각 구해야할 것 같다.
        거리가 inf라면 -1로 출력
    
📚 데이터 구조
    양방향 그래프, 리스트로 그래프 관계성 저장하기
        graph 도착지 인덱스에 [목적지, 가중치] <> 목적지 인덱스에 [도착지, 가중치]
    graph[] << [가중치, 목적지]
    q[] << [현재까지의 가중치, 현재 위치]
    
🎲 test case

⛔️ 실패
    1. 머릿속으로 생각한 구현으로 실패
        pop은 그 곳에 갈지 말지를 결정하는 것이다. 따라서 pop을 하고 거리가 갱신되면 그 곳에서 본격적으로 다음 노드 후보군을 넣으려고 했다.
        그럴려면 다음 노드를 순회하는 과정에서 값을 갱신하지 않고 도착 했을 떄 값을 갱신해야 한다. 도착했을 떄 값을 갱신하려면 prev를 가지고 있어야 한다.
        뭔가 꼬인 듯 하다.
        >> heappop을 했다는 뜻은 일단 그 위치의 노드는 최선의 선택이라는 의미이다. 

📝 후기
    - 다익스트라를 머리에서 끄집어 내는 중에 생각이 꼬여서 잘 못 작동되었다.
    문제 자체는 변형이 거의 없는 쉬운 편이었다.

'''