// [실버4]dp
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

double max_val = 0;

int main() {
  int tc;
  scanf("%d", &tc);
  vector<double> numbers(tc);
  vector<double> dp(tc);

  for (int i = 0; i < tc; ++i) {
    scanf("%lf", &numbers[i]);
  }
  max_val = numbers[0];

  for (int i = 0; i < tc; ++i) {
    for (int j = i; j < tc; ++j) {
      if (i == j) {
        dp[j] = numbers[i];
      }else{
          dp[j] = dp[j - 1] * numbers[j];
      }
      if (max_val < dp[j]) max_val = dp[j];
    }
  }

  printf("%1.3lf\n", round(max_val * 1000) / 1000);

  return 0;
}

// (N^2)/2
/*
8
1.1
0.7
1.3
0.9
1.4
0.8
0.7
1.4
*/