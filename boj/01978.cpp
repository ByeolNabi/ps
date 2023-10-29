#include<iostream>
#include<cmath>

int isPrime(int target_num){
    if(target_num == 1) return 0;
    double n = sqrt(target_num);
    for(int i = 1; i <= n; ++i){
        if(i == 1) continue;
        if(target_num%i==0){
            return 0;
        }
    }
    return 1;
}

int main(){
    int tc; scanf("%d", &tc);
    int cnt = 0;
    while(tc--){
        int number; scanf("%d", &number);
        if(isPrime(number)){
            cnt++;
        }
    }

    printf("%d\n", cnt);
    return 0;
}