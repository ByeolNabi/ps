// 02566 최댓값
#include <iostream>
using namespace std;

int _max[3];

void find_max(int value, int row, int col){
    if(_max[0] <= value){
        _max[0] = value;
        _max[1] = row;
        _max[2] = col;
    }
}

int main(){
    int number;
    for(int row=1; row<=9; ++row){
        for(int col=1; col<=9; ++col){
            cin >> number;
            find_max(number, row, col);
        }
    }
    printf("%d\n%d %d\n", _max[0], _max[1], _max[2]);
    return 0;
}