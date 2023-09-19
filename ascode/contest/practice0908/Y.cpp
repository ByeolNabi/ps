//문제 Y: 중복된 숫자 지우기
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int tc; cin >> tc;
    while(tc--){
        int nums; cin >> nums;
        vector<int> num_arr;
        for(int i = 0; i < nums; ++i){
            int a; cin >> a;
            num_arr.push_back(a);
        }
        sort(num_arr.begin(), num_arr.end());
        vector<int>::iterator last = unique(num_arr.begin(),num_arr.end());
        num_arr.erase(last,num_arr.end());
        for(auto number:num_arr){
            printf("%d ",number);
        }
        printf("\n");

    }
    return 0;
}
//https://kkaeruk.tistory.com/19