//문제 F: 최대로 살 수 있는 사탕의 개수 계산하기 #2
#include<iostream>
using namespace std;

int main(){
    int m, p;
    cin >> m >> p;

    // 사탕을 못 산다면
    if(m < p){
        cout << "Can not buy.\n";
    }else{
        printf("%d %d\n",m/p, m%p);
    }

    return 0;
}