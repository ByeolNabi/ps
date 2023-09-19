#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int size, cases; cin >> size >> cases;
    vector<int> bucket;
    bucket.push_back(0);
    for(int i = 1; i <= size; ++i){
        bucket.push_back(i);
    }
    int start, end;
    while(cases--){
        cin >> start >> end;
        int tmp;
        tmp = bucket[start];
        bucket[start] = bucket[end];
        bucket[end] = tmp;
    }
    for(int i = 1; i <= size; ++i){
        printf("%d ",bucket[i]);
    }
    return 0;
}