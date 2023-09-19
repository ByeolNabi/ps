//문제 B: 원의 면적 구하기
#include<iostream>
using namespace std;

#define PI 3.14159265358979

int main(){
    double radius;
    cin >> radius;
    //반지름 구하기
    radius /= 2;
    //넓이 구하기
    double area = PI*radius*radius;
    printf("%.5f\n", area);

    return 0;
}