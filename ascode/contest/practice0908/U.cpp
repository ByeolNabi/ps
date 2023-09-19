//문제 U: 삼목(tic-tac-toe) 게임 판정하기-Easy
#include<iostream>
using namespace std;

bool is_col(int* arr, int col, int player){
    if(arr[col] == player &&  arr[col+3] == player && arr[col+6] == player){
        return 1;
    }else{
        return 0;
    }
}
bool is_row(int* arr, int col, int player){
    if(arr[col] == player &&  arr[col+1] == player && arr[col+2] == player){
        return 1;
    }else{
        return 0;
    }
}
bool is_cross(int* arr, int player){
    if(arr[0] == player &&  arr[0+4] == player && arr[0+8] == player)return 1;
    else if(arr[0+2] == player &&  arr[0+4] == player && arr[0+6] == player) return 1;
    else return 0;
}
bool is_winner(int* arr, int player){
    if(is_row(arr, 0, player) || is_row(arr, 3, player) || is_row(arr, 6, player) ||
    is_col(arr,0, player)||is_col(arr,1, player)||is_col(arr,2, player) || 
    is_cross(arr,player)) return 1;
    else return 0;
}

int main(){
    int tc; cin >> tc;
    while(tc--){
        int board[9];
        for(int&num:board){
            cin >> num;
        }
        if(is_winner(board, 1)){
            printf("1");
        }else if(is_winner(board,2)){
            printf("2");
        }else{
            printf("draw!");
        }
        printf("\n");
    }

    return 0;
}