# 컨테이너 재배치 : 그리디
import sys
input=sys.stdin.readline

# 입력받기
tc = int(input())
cons = list(map(int,input().split()))
# 평균 구하기
avg = sum(cons)/tc
# upper, lower
lower = int(avg); upper = lower+1;
# result d.s
u_total, d_total = 0, 0
# 순회하며 깍아낼 값 찾기
for h in cons:
    if h < lower:   # 낮다면 채워야 하는 값
        d_total += lower-h
    elif upper < h:  # 높다면
        u_total += h-upper

print(u_total if u_total>d_total else d_total)

'''
🎯 입출력
입력:
    list로 그냥 받아버려
    평탄화를 위한 container 갯수 확인하기

출력:
    위쪽, 아랫쪽 컨테이너 갯수 중 더 큰 값 출력

🔥 알고리즘
    평균 구해서 위 아래 값 정하기
        순회하면서 차이값 구하면서 계속 더해나가기
        아랫값 총합 vs 윗값 총합 구하기
    1. 평균 구하기
    2. 전체탐색하면서 아래 위 컨테이너 깍기
    3. 위, 아래 중 최댓값 출력하기


📚 데이터 구조
    u_total, d_total = 위 아래 컨테이너 자른 값

'''