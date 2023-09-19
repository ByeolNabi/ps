// 문제 H: 오븐 시계 #3
#include <iostream>
using namespace std;

int main()
{
    // 입력 시, 분, 필요한 시간
    int h, m, num;
    cin >> h >> m >> num;

    // start 출력부
    if(h <= 11){
        printf("Cook start->AM%d:%d",h,m);
    } else if(h == 12){
        printf("Cook start->PM%d:%d",h,m);
    } else{
        printf("Cook start->PM%d:%d",h%12,m);
    }
    printf("\n");
    
    // 시간 계산
    m += num;
    h += m/60;
    m %= 60;
    h %= 24;

    // end 출력부
    if(h <= 11){
        printf("Cook end->AM%d:%d",h,m);
    } else if(h == 12){
        printf("Cook end->PM%d:%d",h,m);
    } else{
        printf("Cook end->PM%d:%d",h%12,m);
    }
    printf("\n");

    return 0;
}

// 0~11 : AM0 ~ AM11
// 12~23 : PM12, PM1 ~ PM11