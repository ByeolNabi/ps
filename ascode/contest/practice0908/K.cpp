//문제 K: 팰린드롬 숫자 #1
#include<iostream>
using namespace std;

string str_reverse(string origin){
    string output = "";
    for(int i = 0; i < origin.length(); ++i){
        output += origin[origin.length()-1-i];
    }
    return output;
}
bool str_same(string str1, string str2){
    if(str1 == str2){
        return true;
    }else{
        return false;
    }
}

int main(){
    string str_input;
    cin >> str_input;
    bool p = str_same(str_input, str_reverse(str_input));
    if(p){
        printf("Palindrome!");
    }else{
        printf("No palindrome!");
    }
    return 0;
}