#include <cstdlib>
#include <iostream>
using namespace std;

typedef struct {
  int front;
  int back;
} Pointer;

int main() {
  int list[100001];
  int N;
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &list[i]);
  }
  Pointer ptr_crt = {0, N - 1};

  // init
  int val_max;
  Pointer ptr_max = {0, N - 1};
  val_max = list[ptr_crt.front] + list[ptr_crt.back];

  // 범위를 좁혀라
  while (ptr_crt.front != ptr_crt.back) {
    int val_crt = list[ptr_crt.front] + list[ptr_crt.back];
    if (abs(val_max) < abs(val_crt)) {  // 갱신 필요 없음
      if (val_crt < 0) {
        ptr_crt.front += 1;
      } else {
        ptr_crt.back -= 1;
      }
    } else {  // 갱신 필요함
      val_max = val_crt;
      ptr_max = ptr_crt;
      if (val_crt < 0) {
        ptr_crt.front += 1;
      } else {
        ptr_crt.back -= 1;
      }
    }
  }

  printf("%d %d\n", list[ptr_max.front], list[ptr_max.back]);

  return 0;
}