# [실버5] 집합
import sys

set_temp = set([])
result = []

tc = int(sys.stdin.readline())

for _ in range(tc):
    command = input().split()
    op = command[0]
    # print(command)

    if op == "add":
        set_temp.add(command[1])
    elif op == "remove":
        set_temp.discard(command[1])
    elif op == "check":
        if set_temp.issuperset(set([command[1]])) == True:
            result.append("1")
        else:
            result.append("0")
    elif op == "toggle":
        if command[1] in set_temp:
            set_temp.discard(command[1])
        else:
            set_temp.add(command[1])

    elif op == "all":
        set_temp = set([str(num) for num in range(1, 21)])
    elif op == "empty":
        set_temp.clear()

sys.stdout.write("\n".join(result))
# print(result)
# print()
