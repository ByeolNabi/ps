#include<iostream>
#include<cmath>
using namespace std;

const int r=31, M = 1234567891;

string alphabetToInt(string str){
    string str_number = str;
    for(int i = 0; i<str.length(); ++i){
        str_number[i] = str[i]-'a'+1;
    }
    return str_number;
}
unsigned long long hash_output(string number){
    unsigned long long hash_result = 0;
    for(int i = 0; i < number.length(); ++i){
        if(i==0){
            unsigned long long p = 1;
        }
        else{
            unsigned long long p = ;
        }
    }
    return hash_result%M;
}

int main(){
    int length; scanf("%d", &length);
    string str; cin >> str;
    printf("%llu", hash_output(alphabetToInt(str)));
    return 0;
}

// 모듈러 분배법칙을 이용해서 연산을 줄여야한다.