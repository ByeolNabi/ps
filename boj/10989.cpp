//수 정렬하기 [브론즈1], 많은 인풋
#include<iostream>
#include<queue>
using namespace std;

int arr[10001];
int main(){
    int tc;
    scanf("%d", &tc);
    while(tc--){
        int number;
        scanf("%d", &number);
        arr[number]++;
    }
    for(int i = 1; i < 10001; ++i){
        if(arr[i]==0){
            continue;
        }
        else{
            for(int j = 0; j < arr[i]; ++j){
               printf("%d\n",i);
            }
        }
    }
    
    return 0;
}

/*
메모리 초과 : 천만개를 다 저장해서 메모리 초과가 났다.
해싱을 이용해서 저장하자
틀림: short를 이용해서 오버플로우가 났다.
*/