# Base64 Decoder [D2]

def 문자를표에있는숫자로변환해주는함수(c):
    # 매칭한 표에 맞는 숫자로 바꿔주는 로직
    #return 숫자(10진수)
    pass

def 숫자를이진수string으로변환해주는함수(number):
    # 이걸 자동으로 해주는 메서드가 없을까...?
    #return 여섯자리이진수string
    pass

def encoded된문자를일단이진수로바꿔주는함수(encodedString):
    temp = ""
    for c in encodedString:
        number = 문자를표에있는숫자로변환해주는함수(c)
        biString = 숫자를이진수string으로변환해주는함수(number)
        temp.append(biString)

    return temp

def 이진수string을받으면8개씩가져와서ASCII로변환한후string만드는함수():
    # for문 갈기면 될듯?
    # return 해독된결과물
    pass


def decoder(encodedString):
    이진수로변환된string = encoded된문자를일단이진수로바꿔주는함수(encodedString)
    decodedResult = 이진수string을받으면8개씩가져와서ASCII로변환한후string만드는함수(이진수로변환된string)
    return decodedResult

def main():
    tc = int(input())

    for i in range(tc):
        encodedString = input()
        result = decoder(encodedString)

        print('#{0} {1}'.format(i+1, result))

main()

"""
=============   
💁‍♂️ 문제 설명   
디코딩(해독)하기 단순 구현문제 같다.

🎯 입출력   
tc와 tc갯수 만큼의 문장이 주어진다.

🔥 알고리즘   
숫자를 이진수 리터럴로 변환할 수 있는 무언가가 있으면 좋을 것 같다.
그리고 6비트 이진수를 다 이어붙인 다음에 4비트씩 가져와서 아스키코드로 변환하면 될 것 같다.
- 그래서 4의 배수로 값을 주나보다.
표-1처럼 문자를 숫자로 변환해주는 거는 내가 다 적아야하나... 쉬운 방법은 없을까...
- 아스키로 연속되는 부분만 규칙을 찾을 수 있을 것 같다.

📚 데이터 구조   
⛔️ 실패   
🎲 test case   
📝 후기   
"""