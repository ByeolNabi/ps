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
        reverse(&bucket[start], &bucket[end+1]);
    }
    for(int i = 1; i <= size; ++i){
        printf("%d ",bucket[i]);
    }
    printf("\n");
    return 0;
}