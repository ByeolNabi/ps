def solution(s):
    str_quiz = s;
    str_nums = ['zero','one','two','three','four','five','six','seven','eight','nine']
    for idx in range(len(str_nums)):
        str_quiz = str_quiz.replace(str(str_nums[idx]),str(idx));
    answer = ''.join(str_quiz);
    answer = int(answer);
    answer = 0
    return answer
print(solution("one4seveneight"))