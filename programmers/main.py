class Mode:
    def __init__(self):
        self.answer=''
        self.mode = 0
    def toggle(self):
        self.mode = 0 if self.mode == 1 else 1
    def mode0(self,idx,code):
        if(code[idx] != '1'):
            if(idx%2==0):
                self.answer += code[idx]
        else:
            print('0에서 1로')
            self.toggle()
    def mode1(self,idx,code):
        if(code[idx] != '1'):
            if(idx%2==1):
                self.answer += code[idx]
        else:
            print('1에서 0로')
            self.toggle()        
    def checker(self, idx, code):
        if self.mode==0:
            self.mode0(idx,code)
        elif self.mode==1:
            self.mode1(idx,code)
    def result(self):
        if self.answer=='':
            return 'EMTPY';
        else:
            return self.answer;

def solution(code):
    checker = Mode()
    for idx, c in enumerate(code):
        checker.checker(idx, code)
    answer = checker.result()
    return answer

print(solution('abc1abc1abc'))