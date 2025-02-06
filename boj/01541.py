# [실버2]잃어버린 괄호
import re
from collections import deque


def tokenize(expression):
    return re.findall(r"\d+|[+\-]", expression)  # 연결된 숫자도 찾고, +또는- 도 찾고


def infixToPostfix(infixList):
    postfix = []
    op_stack = []

    for val in infixList:
        if val == "+" or val == "-":
            if op_stack:
                postfix.append(op_stack.pop())
                op_stack.append(val)
            else:
                op_stack.append(val)
        else:
            postfix.append(val)

    while op_stack:
        postfix.append(op_stack.pop())

    return postfix


def cal(postfix):
    result_stack = deque()
    op_stack = []

    for val in postfix:
        if val.isdigit():
            result_stack.append(int(val))
        elif val == "+":
            result_stack.append(result_stack.pop() + result_stack.pop())
        else:
            op_stack.append(val)

    while op_stack:
        result_stack.appendleft(result_stack.popleft() - result_stack.popleft())
        op_stack.pop()

    return result_stack[0]


ipt = input()
# 파싱해서 리스트에 값 입력 (숫자는 숫자로, 문자열을 문자열로, 0때기)
infix = tokenize(ipt)
if len(infix) == 1:
    print(int(infix[0]))
else:
    # infix를 postfix로 변경하기
    postfix = infixToPostfix(infix)

    # postfix를 이용해서 +면 더하고 -면 보류한다. 나머지는 나중에 다 뺀다.
    result = cal(postfix)

    print(result)
