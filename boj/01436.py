# 영화감독 숌 : 실버5
import sys
input = sys.stdin.readline

number = 666;
cnt = 1;
target = int(input())

while cnt != target:
    number += 1;
    if '666' in str(number):
        cnt += 1

print(number)
'''
💁‍♂️ 문제 설명
    666을 포함하는 숫자중 n번쨰로 큰 숫자를 출력하라
🎯 입출력
    N : N번쨰 숫자
🔥 알고리즘
    1. 그냥 브루트포스 해보자
        666을 포함하고 있다는 것을 판단하는 것이 생각보다 귀찮을 것 같다. >> 파이썬이라 in tk
📚 데이터 구조
⛔️ 실패
🎲 test case
📝 후기 + codeReview
    쉽다. 시간제한이 걸리면 머리가 아프겠지만 하지 않겠다.
'''