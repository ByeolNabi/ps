// 문제 T: 과잉수 찾기 #2
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

//for문에 >=를 안 넣어서 문제였다...
int main(){
     int tc; cin >> tc;
    while(tc--){
        int num[2];
        cin >> num[0] >> num[1];
        // 범위의 숫자 순환
        int cnt = 0;    // 과잉수 갯수
        for(int i = num[0]; i <= num[1]; ++i){
            vector<int> solution;
            for(int j = 1; j <= sqrt(i); ++j){
                if(i % j == 0){
                    solution.push_back(j);
                    if(j != i / j && j != 1) solution.push_back(i/j);
                }
            }
            int total = 0;
            for(int sol : solution){
                total+=sol;
            }
            if(total > i){
                cnt++;
            }
        }
        printf("%d-%d:",num[0],num[1]);
        if(cnt == 0){
            printf("NO");
        }else{
            printf("%d",cnt);
        }
        printf("\n");
    }
    return 0;
}
/* 나누기2 이용
int main()
{
    int tc;
    cin >> tc;
    while (tc--) {
        int cnt = 0;
        int num[2];
        cin >> num[0] >> num[1];
        for (int num_range = num[0]; num_range <= num[1]; ++num_range) {
            // 과잉수 판별부
            int total = 0;
            int t_number = num_range;
            for (int i = 1; i < t_number / 2 + 1; ++i) {
                if (t_number % i == 0) {
                    total += i;

                }
            }
            if (t_number < total) {
                cnt++;
            }
        }
        if(cnt != 0){
        printf("%d-%d:%d",num[0],num[1],cnt);
        }else{
            printf("%d-%d:NO",num[0],num[1]);
        }
        printf("\n");
    }
    return 0;
}
*/
/* 제곱근 이용
int main(){
    int tc; cin >> tc;
    while(tc--){
        int num[2];
        cin >> num[0] >> num[1];
        // 범위의 숫자 순환
        int cnt = 0;    // 과잉수 갯수
        for(int i = num[0]; i <= num[1]; ++i){
            vector<int> solution;
            for(int j = 1; j < sqrt(i); ++j){
                if(i % j == 0){
                    solution.push_back(j);
                    if(j != i / j && j != 1) solution.push_back(i/j);
                }
            }
            int total = 0;
            for(int sol : solution){
                total+=sol;
            }
            if(total > i){
                cnt++;
            }
        }
        printf("%d-%d:",num[0],num[1]);
        if(cnt == 0){
            printf("NO");
        }else{
            printf("%d",cnt);
        }
        printf("\n");
    }
    return 0;
}
*/