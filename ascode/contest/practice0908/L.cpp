// 문제 L: 로또 추천 번호 판정하기 - Basic
#include <iostream>
using namespace std;

int arr_sum(int *a, int size)
{
    int total = 0;
    for (int i = 0; i < size; ++i)
    {
        total += a[i];
    }
    return total;
}

int odd_counter(int *a, int size)
{
    int counter = 0;
    for (int i = 0; i < size; ++i)
    {
        if (a[i] % 2 == 1)
        {
            ++counter;
        }
    }

    return counter;
}

int main()
{
    // 6개 입력
    int num[6];
    for (int i = 0; i < 6; ++i)
    {
        cin >> num[i];
    }
    // 총합
    int total = arr_sum(num, 6);
    // 홀수 갯수 리턴
    int odd_c = odd_counter(num, 6);

    int app = 0;
    if (91 <= total && total <= 180)
    {
        ++app;
    }
    if (2 <= odd_c && odd_c <= 4)
    {
        ++app;
    }

    // 출력부
    switch (app)
    {
    case 2:
        printf("BEST\n");
        break;
    case 1:
        printf("GOOD\n");
        break;
    case 0:
        printf("BAD\n");
        break;
    }
    return 0;
}