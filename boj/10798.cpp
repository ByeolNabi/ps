// 세로읽기
#include<iostream>
using namespace std;

int_fast16_t char_mat[5][16];
int main(){
    string tmp;
    for(int i=0; i<5; ++i){
        for(int j=0;j<16;++j){
            char_mat[i][j] = 0;
        }
    }

    for(int i=0; i<5; ++i){
        cin >> tmp;
        for(int j=0; j<tmp.length(); ++j){
            char_mat[i][j] = tmp[j];
        }
    }

    for(int j=0; j<15; ++j){
        for(int i=0; i<5; ++i){
            if(char_mat[i][j] != 0){
                printf("%c", char_mat[i][j]);
            }
        }
    }
    printf("\n");
    return 0;
}