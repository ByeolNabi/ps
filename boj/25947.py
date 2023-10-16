# 25947 선물할인
import sys
input = sys.stdin.readline


# 입력부
n, limit, coup = map(int, input().split())
items = list(map(int, input().split()))
items.sort()

# 변수
tmp_total = 0; total = 0; cnt = 0;
# 슬라이딩 윈도우 구현
left, right = 0, 0;
# 초기 구간 설정하기
while right < coup:
    # 장바구니 담기
    tmp_total += items[right]/2;
    # 초과되었으면 total에 저장x >> 구간 끝내기
    if tmp_total > limit:
        break;
    # 초과 안 되었으면 상태 업데이트 하기
    total = tmp_total
    cnt += 1
    right += 1;

tmp_total = total
# 할인 구간 움직이기 // 값이 초과된다면 Cnt 리턴
while right < n:
    tmp_total += items[left]/2 + items[right]/2
    if tmp_total > limit:
        break;
    total = tmp_total
    cnt += 1
    right += 1
    left += 1

print(cnt)
    




'''
🎯 입출력
    출력 : 장바구니에 담긴 물건의 갯수
🔥 알고리즘
    그리디 : 최선의 선택을 해 나간다.
        일단 할인 구간을 정의한다, 공간이 남는다면 
📚 데이터 구조
⛔️ 실패
'''