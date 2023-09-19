// 문제 M: 재미있는 주사위 게임 #2
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

void arr_minmax(int *arr, int size, int *_min, int *_max)
{
    *_min = arr[0]; *_max = arr[0];
    for(int i = 0; i < size; ++i){
        *_min = *_min>arr[i]?arr[i]:*_min;
        *_max = *_max<arr[i]?arr[i]:*_max;
    }
}

int arr_even(int *a, int size)
{
    int counter = 0;
    for (int i = 0; i < size; ++i)
    {
        if (a[i] % 2 == 0)
        {
            ++counter;
        }
    }

    return counter;
}

int main()
{
    int tc = 0;
    cin >> tc;

    for (int k = 0; k < tc; ++k)
    {
        // 지원, 승환
        int jw[3], sh[3];
        // 입력부
        for (int i = 0; i < 3; ++i)
        {
            cin >> jw[i];
        }
        for (int i = 0; i < 3; ++i)
        {
            cin >> sh[i];
        }

        // 판단부
        // 총합 비교
        if (arr_sum(jw, 3) > arr_sum(sh, 3))
        { // jw승리
            printf("Jiwon wins.");
        }
        else if (arr_sum(jw, 3) < arr_sum(sh, 3))
        { // sh승리
            printf("Seungwhan wins.");
        }
        else
        { // 총합이 같다
            // 최소 최댓값 차이 큰 사람이 승리
            int jw_minmax[2], sh_minmax[2];
            arr_minmax(jw, 3, &jw_minmax[0], &jw_minmax[1]);
            arr_minmax(sh, 3, &sh_minmax[0], &sh_minmax[1]);
            int jw_dif = jw_minmax[1] - jw_minmax[0];
            int sh_dif = sh_minmax[1] - sh_minmax[0];
            if (jw_dif > sh_dif)
            {
                printf("Jiwon wins.");
            }
            else if (jw_dif < sh_dif)
            {
                printf("Seungwhan wins.");
            }
            else
            { // 차이도 같다면
                // 짝수 갯수 비교
                int jw_even = arr_even(jw, 3), sh_even = arr_even(sh, 3);

                if (jw_even > sh_even)
                {
                    printf("Jiwon wins.");
                }
                else if (jw_even < sh_even)
                {
                    printf("Seungwhan wins.");
                }
                else
                {
                    printf("Draw!");
                }
            }
        }
        printf("\n");
    }

    return 0;
}
// 승리 조건
// 총합이 큰 사람이 이긴다. >> arr_sum
// 최댓값 - 최솟값의 차이가 큰 사람이 이긴다. >> arr_max, arr_min
// 짝수 갯수가 많은 사람이 이긴다. >> arr_even
// 승부가 안 나면 비긴다.