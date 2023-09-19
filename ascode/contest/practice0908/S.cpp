// 문제 S: 매트릭스의 합 #2
#include <iostream>
using namespace std;

class matrix
{
public:
    int _row, _col;
    int mat[15][15];
    matrix(int a = 1, int b = 1) : _row(a), _col(b) {}
    // 연산이 가능한가?
    bool is_op(matrix a)
    {
        if (a._row == _row && a._col == _col)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    // 연산하기
    void add(matrix a)
    {
        int counter[2] = {0, 0}; // 음수, 양수
        matrix result(this->_row, this->_col);
        if (is_op(a))
        {
            for (int row = 0; row < this->_row; ++row)
            {
                for (int col = 0; col < this->_col; ++col)
                {
                    result.mat[row][col] = this->mat[row][col] + a.mat[row][col];
                    printf("%d ", result.mat[row][col]);
                    if (result.mat[row][col] < 0)
                    { // 음수 라면
                        ++counter[0];
                    }
                    else if (result.mat[row][col] > 0)
                    { // 양수 라면
                        ++counter[1];
                    }
                }
                printf("\n");
            }
            printf("Positive : %d, Negative : %d\n", counter[1], counter[0]);
        }
        else
        {
            printf("Impossible!\n");
        }
    }
};

int main()
{
    while (1)
    {
        // A입력
        int M1, N1;
        cin >> M1 >> N1;
        matrix A(M1, N1);
        if (M1 == 0 && N1 == 0)
        {
            return 0;
        }
        else
        {
            // A입력받기
            for (int r = 0; r < M1; ++r)
            {
                for (int c = 0; c < N1; ++c)
                {
                    cin >> A.mat[r][c];
                }
            }
        }
        // B입력
        int M2, N2;
        cin >> M2 >> N2;
        matrix B(M2, N2);
        // A입력받기
        for (int r = 0; r < M2; ++r)
        {
            for (int c = 0; c < N2; ++c)
            {
                cin >> B.mat[r][c];
            }
        }
        A.add(B);
        printf("\n");
    }
    return 0;
}
// arr[행][열]