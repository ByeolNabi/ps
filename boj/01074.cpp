// [골드5] Z
#include <iostream>
#include <string>
using namespace std;


namespace recursive {  // 메모리 초과 재귀 => 0 처리를 안 해서 메모리 초과였다.
string bin_gnrtor(int number) {
  if (!number) return "0";
  if (number == 1) {
    return "1";
  }

  return bin_gnrtor(number / 2).append(to_string(number % 2));
}

int bin_sum(string &bin, int start) {  // 1시작, 2시작
  int sum = 0;
  for (int i = 0; i < bin.length(); ++i) {
    if (bin[i] == '1') {
      sum += start << (2 * (bin.length() - 1 - i));
    }
  }

  return sum;
}
}  // namespace recursive

namespace loop {
string bin_gnrtor(int number) {
  if (!number) return "0";
  string result = "";
  while (number != 1) {
    result.append(to_string(number % 2));
    number /= 2;
  }
  return result.append("1");
}

int bin_sum(string &bin, int start) {  // 1시작, 2시작
  int sum = 0;
  for (int i = 0; i < bin.length(); ++i) {
    if (bin[i] == '1') {
      sum += start << (2 * (i));
    }
  }
  return sum;
}
}  // namespace loop

using namespace recursive;
int main() {
  int N, r, c;
  scanf("%d %d %d", &N, &r, &c);

  string row_bin, col_bin;
  row_bin = bin_gnrtor(r);
  col_bin = bin_gnrtor(c);

  // cout << "이진수" << row_bin << " " << col_bin << endl;
  // cout << bin_sum(row_bin, 2) << " " << bin_sum(col_bin, 1) << endl;

  printf("%d\n", bin_sum(row_bin, 2) + bin_sum(col_bin, 1));
  return 0;
}
// 2^15-1 = 32767