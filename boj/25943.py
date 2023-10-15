#25943 양팔저울
import sys



input = sys.stdin.readline
left_w, right_w = 0,0
w_list = [100,50,20,10,5,2,1]
# 입력부
tc = int(input())
stones = map(int, input().split())

# 왼쪽 오른쪽 돌맹이 분배하기
for stone in stones:
    # 1,2번째는 왼쪽 오른쪽으로
    if right_w==0:
        if left_w==0:
            left_w = stone;
        elif right_w==0:
            right_w = stone;
    else: # 3번쨰 이후로
        if left_w == right_w:
            left_w += stone
        else:   # 가벼운 쪽에 돌을 올려둔다.
            if left_w < right_w:
                left_w += stone
            else:
                right_w += stone

diff_lr = abs(left_w-right_w)
def greedy(li, v):
    cnt = 0;
    #v에 li의 큰 값을 빼 나간다.
    for w in li:
        if v==0: break; # 무게가 0이라면 탈출
        if w > v: # 추의 무게가 더 무겁다면 작은 추를 고른다.
            continue;
        else: # 추를 올려도 추가 더 필요한 경우
            while w <= v: # 현재 추가 무게보다 작다면 계속 올린다.
                cnt += 1;   # 추 사용횟수 증가
                v -= w
            continue;
    return cnt;

bw_num = greedy(w_list, diff_lr)
print(bw_num)

'''
🎯 입출력
    tc
    for i in tc: stones;

🔥 생각해볼 문제
    그냥 왼, 오의 값의 차이를 그리디로 줄여나가면 될 듯
    그리디를 이용해 큰 값부터 줄여나가는 함수?
    돌을 놓는 방법은 오,왼,오,왼이 아니다...


📚 데이터 구조
    left_w, right_w
    diff
    w_list = [100,50,20,10,5,2,1]

'''