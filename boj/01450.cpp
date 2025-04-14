// [골드1] 냅색문제

/*
a b c d
2 4 8 16

a,b,c조합에서 d를 더했을 때의 모든 경우의 수는
a,b,c조합 경우의 수 + a,b,c조합에서 d를 추가했을 때의 경우의 수이다.
ex/ (a,b,c) 8가지 (a,b,c)+d => 8가지

S[i]=i번째 물건 무게, i=물건 번호, j=최대 무게 일때,
dp[i][j] = dp[i-1][j] + dp[i-1][j-s[i]];
d를 골랐을 때 (d없을 때 모든 경우의 수) + (d무게를 넣을 수 있는 최대 경우의 수)

🤦‍♂️ 무게가 10^9까지 저장이 가능했다... 내가 배웠던
dp는 1씩 무게를 늘려나가는 거였는데 이거 어떡하지 냅색인척 하는 부분합 문제인가?
-> 냅색처럼 푼다면 최대 30*10^9 = 30,000,000,000

모든 조합을 찾는다면... 2^30 = 1,073,741,824

meet in the middle을 사용하면
2^15 + (2^15 * log2(2^15)) = 524,288
뒷 숫자가 log가 되는 이유는 오름차순 정렬이 되었을 때 upper_bound를 이용해서
값을 찾으면 되기 때문

참고 블로그 : https://blog.naver.com/chogahui05/221374387858

🌞 item을 head, tail로 나눈다.
head에서 만들 수 있는 모든 조합의 무게를 비트마스킹 배열에 저장한다. 배열의
사이즈는 2^head.size() tail도 동일하게 값을 계산한다.

*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  long long result = 0;
  int N, C;
  cin >> N >> C;  // N개 물건, C무게의 가방
  // int는 20억이기 때문에 C 최댓값 10^9보다 작다.
  vector<int> item(N);
  for (int i = 0; i < N; ++i) {
    scanf("%d", &item[i]);
  }

  int mid = N / 2;
  vector<int> head(item.begin(), item.begin() + mid),
      tail(item.begin() + mid, item.end());

  // 15*10^9 = int를 넘는다...
  vector<long long> head_sum(1 << head.size(), 0),
      tail_sum(1 << tail.size(), 0);

  // tail에서 만들 수 있는 모든 조합과 무게
  for (int bit = 0; bit < (1 << tail.size()); ++bit) {
    long long sum = 0;
    for (int i = 0; i < tail.size(); ++i) {
      if (bit & (1 << i)) {
        sum += tail[i];
      }
    }
    tail_sum[bit] = sum;
  }
  sort(tail_sum.begin(), tail_sum.end());  // 정렬 (추후에 under_bound를 위해)

  // head하나와 모든 tail비교하기
  for (int bit = 0; bit < (1 << head.size()); ++bit) {
    long long sum = 0;
    for (int i = 0; i < head.size(); ++i) {
      if (bit & 1 << i) {
        sum += head[i];
      }
    }
    head_sum[bit] = sum;

    // head_sum과 tail_sum을 더했을때 N보다 작은것들 즉,
    // N-head_sum[i]보다 작거나 같은 tail_sum의 idx를 마지막 값을 찾는다.
    // (upper은 어떤 수 n보다 큰 첫번째 val의 iter를 리턴한다.)
    result += upper_bound(tail_sum.begin(), tail_sum.end(), C - head_sum[bit]) -
              tail_sum.begin();
  }

  printf("%lld\n", result);

  return 0;
}