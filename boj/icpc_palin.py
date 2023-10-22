# icpc에서 시간제한이 걸리는 palindrome

# 완전 탐색으로 푼 palin 갯수
def palin_brute(n):
    result = 0
    for i in range(1,n+1):
        if str(i) == str(i)[::-1]:
            result += 1

    return result

# dp로 푼 palin 갯수
def palin_dp(n):
    result = 0
    return result

def main():
    tc = int(input())
    for i in range(tc):
        c = int(input())
        print("브루트 :", palin_brute(c))

main()

'''
💁‍♂️ 문제 설명
    1이상 n이하의 팰린드롬의 갯수찾기
        완전탐색 팰린드롬찾기는 시간초과가 걸린다.
        완전탐색이 아니라 탐색하지 않고 계산으로 바로 할 수 있게 하는 편이 좋을 것 같다.
🎯 입출력
    input : n^10

🔥 알고리즘
    효율적 방법으로 갯수 도출
    브루트포스를 이용해서 정답 검증

    nnnnn자리 숫자가 들어오면 10000에서 nnnnn까지 있는 펠린드롬의 숫자 갯수를 찾는 것이 생각보다 귀찮았다.
        단순히 조합을 찾으면 될 줄 알았는데... 뭔가 안 됨, 1의 자리를 내려서 범위를 배제해나가면서 계산을 하는 편이 좋아보였다.

📚 데이터 구조
⛔️ 실패
    
🎲 test case
📝 후기
'''