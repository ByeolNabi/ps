#include <algorithm>
#include <iostream>
using namespace std;

unsigned long long int info[101];
int number_list[101];

int main() {
  int person_number, tc;
  cin >> person_number >> tc;

  int p;
  for (int i = 0; i < tc; i++) {
    cin >> p;
    for (int j = 0; j < p; j++) {
      cin >> number_list[j];
    }
    sort(number_list, number_list + p);

    // cout << number_list[0] << endl;
    if (number_list[0] == 1) {
      for (int j = 0; j < p; j++) {
        info[number_list[j]] = info[number_list[j]] | 1LL << i;
      }
    } else {
      unsigned long long int attendance = 0;
      for (int j = 0; j < p; j++) {
        attendance = attendance | info[number_list[j]];
      }
      for (int j = 0; j < p; j++) {
        info[number_list[j]] = attendance;
      }
    }
  }
  int tmp = 100;
  for (int j = 1; j <= person_number; j++) {
      if (info[1] == info[j]) {
        cout << j << endl;
    }
  }

  return 0;
}