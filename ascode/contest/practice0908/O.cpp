//문제 O: 탑 그리기 #2
#include<iostream>
using namespace std;

void rect(int floor){
    for(int row = 0; row < floor; ++row){
        for(int col = 0; col < floor*2-1; ++col){
            printf("%%");
        }
        printf("\n");
    }
}
void tri(int floor, int top){
    if(floor == 0){
        return;
    }
    tri(floor-1, top);
    // floor층에서는 (top-floor, floor*2-1, top-floor)개 만큼 그린다.
    for(int i = 0; i < top-floor; ++i){
        printf(" ");
    }
    for(int i = 0; i < floor*2-1; ++i){
        printf("%%");
    }
    for(int i = 0; i < top-floor; ++i){
        printf(" ");
    }
    printf("\n");
}

int main(){
    int tc;
    cin >> tc;

    for(int i = 0; i < tc; ++i){
        //입력부
        int floor;
        cin >> floor;
        rect(floor);
        tri(floor, floor);
        printf("\n");
    }

    return 0;
}