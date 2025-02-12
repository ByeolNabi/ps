# [실버4] 동전 0
# 각 동전은 이전 동전을 약수로 가지고 있기 때문에 그리디가 유효하다.
import sys

data = sys.stdin.read().splitlines()
coinType, target = map(int, data[0].split())

count = 0
for i in range(coinType, 0, -1):
    
    crtCoin = int(data[i])
    # 동전이 target과 같거나 작다면.
    if target==0:
        break
    elif crtCoin <= target:
        # 나눈다
        count += target // crtCoin
        target = target % crtCoin
    
print(count)

# 여러번 빼야한다면 나눠라