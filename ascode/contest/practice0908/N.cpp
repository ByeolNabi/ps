// 문제 N: 스마트폰 구매 대작전 #5
#include <iostream>
using namespace std;

int main()
{
    int tc;
    cin >> tc;

    for (int i = 0; i < tc; ++i)
    {
        int wage[7] = {40000, 40000, 40000, 40000, 40000, 90000, 90000};
        int price, total_m = 0;
        cin >> price;

        int count = 0;
        while (total_m < price)
        {
            total_m += wage[count++ % 7];
        }
        cout << count << endl;
    }

    return 0;
}