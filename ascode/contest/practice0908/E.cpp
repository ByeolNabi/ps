//문제 E: 나머지 구하기 #2
#include<iostream>
using namespace std;

int main(){
    unsigned int num[4];
    for(int i = 0; i < 4; ++i){
        cin >> num[i];
    }

    unsigned int result = (num[0]*num[1]) % (num[2]+num[3]);
    cout << result;

    return 0;
}