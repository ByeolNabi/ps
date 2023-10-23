// 브론즈1 그리디
#include<iostream>
int main(){
    int L, P, V;    // P일중 L일 사용가능, 휴가 V일
    int cnt = 1;
    while(true){
        scanf("%d %d %d", &L, &P, &V);
        if(L+P+V == 0) return 0;
        printf("Case %d: %d\n", cnt++, (V/P)*L + (V%P <= L ? V%P : L));
    }
    return 0;
}