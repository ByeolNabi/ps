# [실버5] 집합
import sys

set_temp = set([])
result = []

tc = int(sys.stdin.readline())

for _ in range(tc):
    command = sys.stdin.readline().split()
    op = command[0]
    # print(command)

    if op == "add":
        set_temp.add(command[1])
    elif op == "remove":
        set_temp.discard(command[1])
    elif op == "check":
        if command[1] in set_temp:
            sys.stdout.write("1")
        else:
            sys.stdout.write("0")
    elif op == "toggle":
        if command[1] in set_temp:
            set_temp.discard(command[1])
        else:
            set_temp.add(command[1])

    elif op == "all":
        set_temp = {'1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20'}
    elif op == "empty":
        set_temp.clear()

# print(result)
# print()
