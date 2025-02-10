# [실버4]나는야 포켓몬 마스터 이다솜
import sys

input = sys.stdin.readline

pokeNumToName = [0]
pokeNameToNum = {}
result = []

words, tests = map(int, input().split())

for i in range(words):
    poke = input().strip()
    pokeNumToName.append(poke)
    pokeNameToNum[poke] = i + 1

for i in range(tests):
    target = input().strip()
    if target.isdigit():
        result.append(pokeNumToName[int(target)])
    else:
        result.append(str(pokeNameToNum[target]))

sys.stdout.write("\n".join(result))