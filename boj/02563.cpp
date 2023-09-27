// 02563 색종이
#include<iostream>
using namespace std;

int _mat[101][101];
int cnt;
void checker(int x, int y){
    for(int row=0; row<10; ++row){
        for(int col=0; col<10; ++col){
            if(_mat[x+row][y+col] == 0){
                ++cnt;
                _mat[x+row][y+col] = 1;
            }
        }
    }
}

int main(){
    int tc;
    cin >> tc;
    int coor[2];
    while(tc--){
        cin >> coor[0] >> coor[1];
        checker(coor[0], coor[1]);
    }
    printf("%d\n", cnt);
    return 0;
}