// 문제 W: 과수, 야채 심기
#include <iostream>
using namespace std;

char trees[11] = {'0','A','B','C','D','G','K','M','P','S','W'};
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int size;
        cin >> size;
        if (size % 2 == 1)
        { // 홀수
            for (int i = size / 2 + 1; i > 1; --i)
            { // 상단
                for (int alp = size / 2 + 1; alp > 1; --alp)
                { // 감소
                    char alpha = i >= alp ? i : alp;
                    printf("%c", trees[alpha]);
                }
                for (int alp = 1; alp <= size / 2 + 1; ++alp)
                { // 증가
                    char alpha = i >= alp ? i : alp;
                    printf("%c", trees[alpha]);
                }
                printf("\n");
            }
            for (int i = 1; i <= size / 2 + 1; ++i)
            { // 하단
                for (int alp = size / 2 + 1; alp > 1; --alp)
                { // 감소
                    char alpha = i >= alp ? i : alp;
                    printf("%c", trees[alpha]);
                }
                for (int alp = 1; alp <= size / 2 + 1; ++alp)
                { // 증가
                    char alpha = i >= alp ? i : alp;
                    printf("%c", trees[alpha]);
                }
                printf("\n");
            }
        }
        else
        { // 짝수
            for (int i = size / 2; i >= 1; --i)
            { // 상단
                for (int alp = size / 2; alp >= 1; --alp)
                { // 감소
                    char alpha = i >= alp ? i : alp;
                    printf("%c", trees[alpha]);
                }
                for (int alp = 1; alp <= size / 2; ++alp)
                { // 증가
                    char alpha = i >= alp ? i : alp;
                    printf("%c", trees[alpha]);
                }
                printf("\n");
            }
            for (int i = 1; i <= size / 2; ++i)
            { // 하단
                for (int alp = size / 2; alp >= 1; --alp)
                { // 감소
                    char alpha = i >= alp ? i : alp;
                    printf("%c", trees[alpha]);
                }
                for (int alp = 1; alp <= size / 2; ++alp)
                { // 증가
                    char alpha = i >= alp ? i : alp;
                    printf("%c", trees[alpha]);
                }
                printf("\n");
            }
        }
        printf("\n");
    }

    return 0;
}