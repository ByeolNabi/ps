# 25947 그리디, 장바구니 담기
import sys
input=sys.stdin.readline

# 입력부
n, limit, coup = map(int,input().split())
items = list(map(int, input().split()))   # 오름차순 정렬
items.sort()
items.append(float('inf'))

# 그리디 실행
ptr_in=0; ptr_out=0; total=0; count=0;

# 하나 넘칠 때 까지 담기
while total <= limit:
    if ptr_out >= n:
        break;
    total += items[ptr_out];
    ptr_out += 1; count += 1;
# print("while :", total)
if not(ptr_out >= n):
    count -= 1; ptr_out -= 1;
    total -= items[ptr_out]

ptr_in = ptr_out-1;
# 경계선을 중심으로 쿠폰 사용해 나가기
while coup!=0:
    if items[ptr_out] == float('inf'):
        break;
    if total+(items[ptr_out])/2 <= limit:   # 할인해서 물건을 추가할 수 있다면
        coup -= 1;
        # 추가해야지
        total = total+(items[ptr_out])/2;
        ptr_out += 1; count+=1;
    else:   # 할인해도 물건을 추가할 수 없다면,
        coup -= 1;
        # 가지고 있는 것에서 할인을 해야지
        total -= items[ptr_in]/2;
        ptr_in -= 1;

print(count)

'''
🎯 입출력
    입력 : n, b, coup = 선물 갯수, 한계 무게, 할인 갯수
    출력 : result = 담을 수 있는 선물 갯수
🔥 알고리즘
    그리디
        1. 선물의 무게를 오름차순 정렬한 후, 가장 작은 숫자를 계속 담는다. (최선의 선택)
        2. 선물을 더 이상 담을 수 없다면, 할인쿠폰을 사용한다.
            > 밖에서 가장 저렴한 물건에 할인쿠폰을 사용한다.
            > 담을 수 없다면, 가지고 있는 것 중에서 가장 비싼 것에 쿠폰을 쓴다.
            2.번을 반복한다.
    리스트를 바로 가져다가 포인터로 구현하는 것이 나을까...??
    어쨋든... 예, 화이팅

    while을 이용해서 장바구니에 담았기 떄문에 (한개를 더 담은 상태 + ptr, count가 한 칸 넘아간 상태)
📚 데이터 구조
    선물 저장 배열,
    장바구니 배열,
    쿠폰 갯수,
    포인터?
        왼포인터(장바구니에서 가장 비싼 물건), 오른 포인터(다음 물건)
⛔️ 실패
    out of index 관리하기 >> 장바구니가 비어서 더 담고 싶을 때 index를 초과한다.
        out of index를 관리하기 위해서 그냥 끝에 마지막이라는 토큰을 넣어두자.

반례
3 10 0
1 2 7
>>3
1 1 1
2
>>1
3 3 3
2 2 2
>>3
3 6 3
2 4 6
>>3
3 10 2
2 4 6
>>3
'''