# 06087 다익스트라? 표 탐색
import heapq
import sys
input = sys.stdin.readline

WALL = 8
END = 1
ROAD = 0

# crt+1 + 
# [0]:오른, [1]:아래, [2]:왼쪽, [3]:위
# [0]:아래, [1]:오른, [2]:위쪽, [3]:왼
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

cnt = -1;
def toggle():
    global cnt;
    cnt += 1;
    return cnt;

def main():
    # 입력부
    col, row = map(int, input().split())
    board_origin = []
    for _ in range(row):
        tmp = input()
        board_origin.append(tmp)
    # 자료구조
    endPoint = [0,0]

    # 그래프 만들기
    def init_graph(road, end, wall):
        # graph 만들기
        switch = {'.':road,'C':end,'*':wall,'\n':wall}
        graph = [[wall]*(col+2)]
        for idx_r, line in enumerate(board_origin):
            tmp=[wall]
            for idx_c, c in enumerate(line):
                tmp.append(switch[c])
                if c=='C':
                    endPoint[toggle()] = [idx_r+1, idx_c+1]

            graph.append(tmp)

        graph.append([wall]*(col+2))
        return graph;
    graph = init_graph(END, ROAD, WALL)

    # 시작점에서 다익스트라 실행하기
    def dijkstra():
        # 최단거리 저장하는 배열, 방향 저장 배열
        distance = [[float('inf') for _ in range(col+2)] for _ in range(row+2)]
        dxdy = [[WALL for _ in range(col+2)] for _ in range(row+2)]
        # 첫 위치로 초기화하기
        distance[endPoint[0][0]][endPoint[0][1]] = 0
        q = []

        # 상하좌우 넣기
        for i in range(4):
            # 벽이면 넣지마, 아니면 q에 넣어
            if graph[endPoint[0][0]+dx[i]][endPoint[0][1]+dy[i]] != WALL:
                # distance와 dxdy를 초기화한다.
                distance[endPoint[0][0]+dx[i]][endPoint[0][1]+dy[i]] = 0;
                dxdy[endPoint[0][0]+dx[i]][endPoint[0][1]+dy[i]] = i;
                # (방향, 현재 노드의 가중치, 현재노드=[좌표, 좌표])
                heapq.heappush(q, (i,0,[endPoint[0][0]+dx[i],endPoint[0][1]+dy[i]]))

        # 큐 순회하기
        while q:
            # for line in distance:
            #     for c in line:
            #         print("{0:3d},".format(c), end='')
            #     print()
            # print('==================================')
            # 다음 노드로 이동하기

            # print(q)
            crt_direct, crt_cost, coor = heapq.heappop(q)
            crt_r, crt_c = coor
            # 현재 위치에서 다음 동선 갱신 가능한지 순회하기
            for delta in range(4):
                if graph[crt_r+dx[delta]][crt_c+dy[delta]] != WALL: # 벽이 아니면 전진
                    next_cost = distance[crt_r+dx[delta]][crt_c+dy[delta]]
                    next_dxdy = dxdy[crt_r+dx[delta]][crt_c+dy[delta]]

                    if crt_direct == delta: # 같은 방향이라면 가중치 더하기x
                        # 현재 가중치 + 다음 가중치 < 다음 노드의 distance보다 작으면 큐에 넣기
                        if (crt_cost < next_cost if ((next_dxdy+2)%4 == crt_direct)or(next_dxdy == crt_direct) else crt_cost <= next_cost) : # 역방향이거나 순방향이면 작을때 갱신
                            # 일단 후보군에 넣어
                            heapq.heappush(q, (delta, crt_cost, [crt_r+dx[delta],crt_c+dy[delta]]))
                            # 일단 후보군의 distance를 갱신하기
                            distance[crt_r+dx[delta]][crt_c+dy[delta]] = crt_cost
                            continue;
                    elif crt_direct == (delta+2)%4: # 반대 방향이면 넣지 않기
                        continue;
                    else: # 좌우라면 가중치 + 1
                        # 현재 가중치 + 다음 가중치 < 다음 노드의 distance보다 작으면 큐에 넣기
                        if (crt_cost + 1 < next_cost if ((next_dxdy+2)%4 == crt_direct)or(next_dxdy == crt_direct) else crt_cost + 1 <= next_cost): 
                            # 일단 후보군에 넣어
                            heapq.heappush(q, (delta, crt_cost+1, [crt_r+dx[delta],crt_c+dy[delta]]))
                            # 일단 후보군의 distance를 갱신하기
                            distance[crt_r+dx[delta]][crt_c+dy[delta]] = crt_cost + 1
                            continue;

        # 그래프 디버깅
        # for line in graph:
        #     for c in line:
        #         print(str(c)+' ', end='')
        #     print()
        
        return distance[endPoint[1][0]][endPoint[1][1]]
    result = dijkstra()
    return result;

if __name__ == '__main__':
    print(main())

'''
🎯 입출력
    입력 : max >> 100*100 사이즈 표 입력
    출력 : 필요한 거울의 갯수
🔥 알고리즘
    델타탐색?, 다익스트라(가중치가 서로 다름), 
    전진이 아닌 꺽이는 상황에서 가중치를 1 올린다.
        유동적으로 가중치 만들기
    다익스트라의 최소힙을 사용해서 다음 탐색할 공간을 찾는다.
    1. 현재 위치에서 다음 위치 후보군을 최소힙에 넣는다.
    2. 다음 위치는 최소힙.pop이 정해주기 때문에 신경쓰지 말고 pop하자
    3. c에 도착하면, c의 값 출력
📚 자료구조
    다익스트라를 위한 자료구조
        최소힙, distance
        현재 위치 + 다음 위치의 가중치 = cst
    그래프 표현 방법
        겉은 벽으로 한 번 감싸는 편이 더 편하게 탐색할 수 있을 것이다.
        w, h가 주어지니 w+2, h+2 크기의 배열을 만들자
        숫자로 변경해서 저장한다.
        {',':0, 'C':1, '*':-1}
    dijkstra(){
        # 초기 설정하기
        큐
        최저거리 저장 배열
        # 큐 선회하기
        현재 거리
    }
    heapq.heappush(q, (delta, crt_cost, [crt_r+dx[delta],crt_c+dy[delta]]))
    >> (방향, 현재 노드의 가중치, 현재노드=[좌표, 좌표])
    
⛔️ 실패
    1. 탐색 도중 out of index를 방지하기 위해서 벽으로 둘러쌓았기 때문에 endpoint와 동기화가 안 되었다.
        >> endPoint의 x, y 좌표를 한 개씩 더해주었다.
    2. 처음 시작할 때 임의로 1의 방향으로 지정하고 움직임을 주었더니 처음 위치에서 첫 발걸음의 가중치가 1이 되어버리는 상황이 되어서 이상해진다.
        >> 가장 첫 발걸음에서 상하좌우의 노드를 미리 추가해주었다.
    3. 목적지에 도착하자마자 루프를 빠져나오게 만들었다. 최소가중치인 상태로 벽에 부딪히면 옆에 있는 값을 갱신한다. 그때 목적지가 있다면 최솟값을 찾지 않고 종료시킨다.
        >> 그냥 큐가 빌때까지 while을 돌리면 된다.
    4. 가중치가 작아질때만 덮어씌우고 큐에 넣었다. 그렇다면 x자로 교차되는 상태에서 하나의 방향을 버려야했다.
        >> 같거나 작아질떄 덮어씌우고 큐에 넣자.
    5. 같거나 작아질 때 덮어씌우면 같을 때에도 큐에 넣게 된다. 그러면 너무 많은 후보들을 넣게 되나?
        >> 직각일 때만 작거나 같다를 적용하자 +-1을 4로 나눈 나머지일때면 작거나 같다 적용하기
    6. 특정한 tc에서 너무 많은 값들이 큐에 쌓인다. 왜 쌓이는거지?
        >> 100 7 사이즈의 인풋을 넣으면 큐에 중복된 값이 너무 많아진다. 분기점에서 분기하고 한 곳에 모이고 모인 곳에서 각각 분기하면 2배가 된다.
        >> (next_dxdy+2%4) 괄호를 안 쳤다.
    7. dx, dy를 헷갈렸네? 괜찮겠지~
    
🎲 test case
    >> input
7 8
.......
......C
......*
*****.*
....*..
....*..
.C..*..
.......
    << output
3
    
    >> input
4 6
.C..
....
....
**.*
....
...C
    << output
2

    >> input
100 7
...*...*...*...*...*...*...*...*...*...*...*...*...*...*...*...*...*...*...*...*...*...*...*...*...*
C*...*...*...*...*...*...*...*...*...*...*...*...*...*...*...*...*...*...*...*...*...*...*...*...*.*
...*...*...*...*...*...*...*...*...*...*...*...*...*...*...*...*...*...*...*...*...*...*...*...*...*
**************************************************************************************************.*
...*...*...*...*...*...*...*...*...*...*...*...*...*...*...*...*...*...*...*...*...*...*...*...*...*
C*...*...*...*...*...*...*...*...*...*...*...*...*...*...*...*...*...*...*...*...*...*...*...*...*.*
...*...*...*...*...*...*...*...*...*...*...*...*...*...*...*...*...*...*...*...*...*...*...*...*...*
    << output
196
    
'''