//문제 G: 마법의 수 찾아내기 #3
#include <iostream>
using namespace std;

int main(){
    int num;
    cin >> num;

    if((num%2==1&&num%3==0)||(num%7==0&&num%17==0)){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }

    return 0;
}