# [실버4] 듣보잡
import sys

input = sys.stdin.read  # 모든 입력 한 번에 받는 방법


def main():
    data = input().splitlines()

    # for문으로 반복하려고 했는데, 리스트로 잘라서 딕셔너리로 만드는 코드가 있었다.
    hear, see = map(int, data[0].split())  # (듣도, 보도) 못한 놈

    hearList = data[1 : hear + 1]
    hearDict = {name: 1 for name in hearList}

    result = []
    count = 0
    for val in data[hear + 1 :]:
        if hearDict.get(val):
            result.append(val)
            count += 1

    result.sort()
    print(count)
    print("\n".join(result))


if __name__ == "__main__":
    main()
