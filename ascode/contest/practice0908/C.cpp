//문제 C: 관객수 통계 구하기
#include<iostream>
using namespace std;

int main(){
    int visitor[7];
    double total = 0;
    // 입력 밑 총합 구하기
    for(int i = 0; i < 7; ++i){
        cin >> visitor[i];
        total += visitor[i];
    }
    // 평균
    double avg = total/7;

    printf("%.0f %.9lf\n",total, avg);

    return 0;
}