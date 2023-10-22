//수 정렬하기 [브론즈1], 많은 인풋
#include<iostream>
#include<queue>
using namespace std;

int main(){
    priority_queue<int, vector<int>, greater<int>> q;
    int tc;
    scanf("%d", &tc);
    int data;
    while(tc--){
        scanf("%d", &data);
        q.push(data);
    }
    int sz = q.size();
    while(sz--){
        printf("%d\n", q.top());
        q.pop();
    }
    return 0;
}

/*
메모리 초과 : 천만개를 다 저장해서 메모리 초과가 났다.
해싱을 이용해서 저장하자
*/