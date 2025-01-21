# [실버3]1로 만들기 // 아래에서부터 3가지 연산을 사용해서 최소 연산 값을 갱신해나가면 될 것 같다.

target = int(input())
memo = [1000001] * (target+1)  # 0, 1, 2, 3까지는 정의해두기 (작은 수만 저장하고싶어서 큰수로 초기화)
memo[1] = 0

for crt in range(2, target+1):
    # 나누고 더한 후 minimum을 저장하자
    if crt % 3 == 0:
        memo[crt] = min(memo[crt], memo[crt // 3] + 1)

    if crt % 2 == 0:
        memo[crt] = min(memo[crt], memo[crt // 2] + 1)

    memo[crt] = min(memo[crt], memo[crt - 1] + 1)

print(memo)