# [실버5] 집합
import sys

result = set([])
MAX = set([num for num in range(1, 21)])

datas = sys.stdin.read().splitlines()
tc = int(datas[0])

# print(datas[1:])
for val in datas[1:]:
    command = val.split()
    op = command[0]
    # print(command)

    if op == "add":
        result.add(int(command[1]))
    elif op == "remove":
        result.discard(int(command[1]))
    elif op == "check":
        if result.issuperset(set([int(command[1])])) == True:
            print(1)
        else:
            print(0)
    elif op == "toggle":
        result = result.symmetric_difference(set([int(command[1])]))
    elif op == "all":
        result = MAX
    elif op == "empty":
        result.clear()
    # print(result)
    # print()