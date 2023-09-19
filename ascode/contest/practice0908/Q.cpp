// 문제 Q: 최저가 5 제품의 평균 가격 구하기
#include <iostream>
#include <algorithm>
using namespace std;

int arr_sum(short *arr, int size)
{
    int total = 0;
    for (int i = 0; i < size; ++i)
    {
        total += arr[i];
    }
    return total;
}

int main()
{
    int tc;
    cin >> tc;
    for (int k = 0; k < tc; ++k)
    {
        // 넉넉하게 잡아두자
        short price[101];
        short size;
        cin >> size;
        for (int i = 0; i < size; ++i)
        {
            cin >> price[i];
        }
        sort(price, price + size);
        int total = arr_sum(price, 5);
        printf("%.1f\n",total/5.);
    }
    return 0;
}