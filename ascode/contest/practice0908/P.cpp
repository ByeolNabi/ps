// 문제 P: 알파벳 다이아몬드 #2
#include <iostream>
using namespace std;

int main()
{
    int tc;
    cin >> tc;
    for (int i = 0; i < tc; --tc)
    {
        int n;
        cin >> n;
        // 일단 반복시키고 생각하자(하나의 반복문으로 모양을 만들어 낼 필요는 없다.)
        // 선현적인 패턴들로 for문을 나누는 것이 중요할 것 같다.
        for (int row = 0; row < n; ++row)
        { // 상단 세모
            for (int i = 0; i < n - (row + 1); ++i)
            {
                printf(" ");
            }
            // for(int i = 0; i < (row+1)*2-1; ++i){
            //     printf("O");
            // }
            // 알파벳 출력
            for (int j = 0; j < row + 1; j++)
            { // 알파벳 증가
                printf("%c", 65 + j);
            }
            for (int j = row - 1; j >= 0; --j)
            { // 알파벳 감소
                printf("%c", 65 + j);
            }
            printf("\n");
        }
        for (int row = n - 1; row > 0; --row)
        { // 하단 세모
            for (int i = 0; i < n - row; ++i)
            {
                printf(" ");
            }
            // for(int i = 0; i < row*2-1; ++i){
            //     printf("O");
            // }
            for (int j = 0; j < row; j++)
            { // 알파벳 증가
                printf("%c", 65 + j);
            }
            for (int j = row - 2; j >= 0; --j)
            { // 알파벳 감소
                printf("%c", 65 + j);
            }
            printf("\n");
        }
    }
    return 0;
}
// A(65)