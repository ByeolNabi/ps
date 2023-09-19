//문제 V: 로또 당첨 번호 빈도수 확인하기
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(const pair<int, int>&a, const pair<int, int>&b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second > b.second;
}

int main(){
    vector<int> lottery;
    int tc; cin >> tc;
    // 입력받기
    while(tc--){
        for(int i = 0; i < 6; ++i){
            int number; cin >> number;
            lottery.push_back(number);
        }
    }
    // 갯수 세기 및 저장
    vector<pair<int, int>> stat;
    for(int i = 1; i <= 45; ++i){
        int cnt = count(lottery.begin(), lottery.end(), i);
        stat.push_back(make_pair(i,cnt));
    }
    sort(stat.begin(), stat.end(), compare);
    for(int i = 0; i < 6; ++i){
        printf("%d ",stat[i].first);
    }
    printf("\n");
    return 0;
}
// https://withhamit.tistory.com/195 >> pair 정렬