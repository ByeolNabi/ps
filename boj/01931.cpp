// [골드5] 회의실 배정
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool comp(pair<unsigned int, unsigned int> a,
          pair<unsigned int, unsigned int> b) {
  if (a.second == b.second) {
    return a.first < b.first;
  }

  return a.second < b.second;
}

int main() {
  int tc;
  cin >> tc;
  vector<pair<unsigned int, unsigned int>> time_table(
      tc, pair<unsigned int, unsigned int>(0, 0));

  int tmp1, tmp2;
  for (int i = 0; i < tc; ++i) {
    cin >> tmp1 >> tmp2;
    time_table[i].first = tmp1;
    time_table[i].second = tmp2;
  }

  sort(time_table.begin(), time_table.end(), comp);

  unsigned int cnt = 1;
  unsigned int end_time = time_table[0].second;
  for (int i = 1; i < tc; ++i) {
    if (time_table[i].first >= end_time) {  // 안 겹치면 선택
      ++cnt;
      end_time = time_table[i].second;
    }
  }

  printf("%d\n", cnt);

  return 0;
}

/*
(start, end)를 정렬할 때
end로만 정렬할게 아니라 start도 정렬해야한다.
order by ASC start, end;
*/