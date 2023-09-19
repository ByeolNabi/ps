//다이얼
#include<iostream>
using namespace std;

int hasing(char c){
    if('A'<=c && c<='C'){
        return 2;
    }else if('D' <=c && c<= 'F'){
        return 3;
    }else if('G' <=c && c<= 'I'){
        return 4;
    }else if('J' <=c && c<= 'L'){
        return 5;
    }else if('M' <=c && c<= 'O'){
        return 6;
    }else if('P' <=c && c<= 'S'){
        return 7;
    }else if('T' <=c && c<= 'V'){
        return 8;
    }else if('W' <=c && c<= 'Z'){
        return 9;
    }else{
        return 0;
    }
}

int main(){
    string numb;
    cin >> numb;
    int total = 0;
    for(int i = 0; i < numb.length(); ++i){
        total += hasing(char(numb[i]))+1;
    }
    printf("%d\n",total);
    return 0;
}