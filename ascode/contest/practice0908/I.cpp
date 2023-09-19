//문제 I: 이차방적식과 근의 판별 #3
#include<iostream>

using namespace std;
int main(){
    float D;
    float a, b, c;
    cin >> a >> b >> c;

    D = (b*b)-(4*a*c);

    if(D>0){
        printf("Real");
    }else if(D==0){
        float sol;
        sol = -(b/(2*a));
        if(sol == 0){
            printf("0.00");
        }else{
            printf("%.2f",sol);
        }
    }else{
        printf("Imaginary");
    }

    return 0;
}
// 연산자 우선순위 주의하기