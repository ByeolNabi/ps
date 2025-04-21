// [실버3] 서바이벌, 도형 그리기
#include <iostream>
using namespace std;

int *coor1 = new int[2];
int *coor2 = new int[2];
int *first_coor = new int[2];

float *prev_gradient = new float;
float *crt_gradient = new float;
float *first_gradient = new float;

int result = 1;

void swap(int *ptr1, int *ptr2) {
  int *tmp;
  tmp = ptr1;
  ptr1 = ptr2;
  ptr2 = tmp;
}

int main() {
  int tc;
  cin >> tc;

  cin >> coor1[0] >> coor1[1];
  cin >> coor2[0] >> coor2[1];

  prev_gradient[0] = 1. * (coor2[0] - coor1[0]) / (coor2[1] - coor1[1]);

  // 마지막 선과 연결해야하기 떄문에 따로 저장함
  first_coor[0] = coor1[0];
  first_coor[1] = coor1[1];
  first_gradient[0] = prev_gradient[0];

  for (int i = 2; i < tc; ++i) {
    swap(coor1, coor2);
    cin >> coor2[0] >> coor2[1];  // 그다음 좌표 받기

    crt_gradient[0] =
        (coor2[0] - coor1[0]) / (coor2[1] - coor1[0]);  // 기울기 계산

    // 기울기 비교
    // (기울기가 같거나, 기울기가 반전되거나) 같은 궤도를 지나간다.
    if (crt_gradient[0] == prev_gradient[0]) {
      // 넘어가
    } else {  // 다른 궤도를 지나가면 더하기
      ++result;
    }
    swap(crt_gradient, prev_gradient);  // 다음 값을 맞이할 준비
  }

  // 마지막과 처음 연결하기
  crt_gradient[0] = 1. * (first_coor[0] - coor2[0]) /
                    (first_coor[1] - coor2[1]);  // 기울기 계산

  if (crt_gradient[0] == first_gradient[0]) {
    // 넘어가
  } else {  // 다른 궤도를 지나가면 더하기
    ++result;
  }

  cout << ((result < 3) ? -1 : result) << endl;

  return 0;
}