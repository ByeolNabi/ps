//문제 R: n의 배수 세기
#include<iostream>
using namespace std;

int main(){
    int numbers[101];   //넉넉하게
    int tc; cin >> tc;
    while(tc--){
        int inputs; cin >> inputs;
        // 판별하고 싶은 값 입력
        for(int i = 0; i < inputs; ++i){
            int num; cin >> num;
            numbers[i] = num;
        }
        // 배수의 기준 입력
        cin >> numbers[100];
        // 배수의 갯수 찾기
        int cnt = 0;
        for(int i = 0; i < inputs; ++i){
            if(numbers[i]%numbers[100]==0){
                ++cnt;
            }
        }
        // 배수 갯수 출력
        printf("%d\n",cnt);
    }
    return 0;
}
//나머지가 0이면 count++