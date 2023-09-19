//문제 D: 문자 출력하기 #2
#include<iostream>
using namespace std;

int main(){
    int c[3];
    // 입력 부분
    for(int i = 0; i < 3; ++i){
        cin >> c[i];
    }
    // 출력 부분
    for(int i = 0; i < 3; ++i){
        printf("%c\n",c[i]);
    }

    return 0;
}