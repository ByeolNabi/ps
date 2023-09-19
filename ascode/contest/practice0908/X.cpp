// 문제 X: 오목
#include <iostream>
#define BLACK 1
#define WHITE 2
using namespace std;

int board[20][20];
// 8방향 체킹하기
// 상, 하, 좌, 우
// 좌상, 우상, 좌하, 우하,
bool dir_N(int row, int col, int player)
{
    if (board[row][col] == player) {
        if (board[row][col - 1] == player) {
            if (board[row][col - 2] == player) {
                if (board[row][col - 3] == player) {
                    if (board[row][col - 4] == player) {
                        return 1;
                    } else
                        return 0;
                } else
                    return 0;
            } else
                return 0;
        } else
            return 0;
    } else
        return 0;
    return 0;
}
bool dir_S(int row, int col, int player)
{
    if (board[row][col] == player) {
        if (board[row][col + 1] == player) {
            if (board[row][col + 2] == player) {
                if (board[row][col + 3] == player) {
                    if (board[row][col + 4] == player) {
                        return 1;
                    } else
                        return 0;
                } else
                    return 0;
            } else
                return 0;
        } else
            return 0;
    } else
        return 0;
    return 0;
}
bool dir_W(int row, int col, int player)
{
    if (board[row][col] == player) {
        if (board[row - 1][col] == player) {
            if (board[row - 2][col] == player) {
                if (board[row - 3][col] == player) {
                    if (board[row - 4][col] == player) {
                        return 1;
                    } else
                        return 0;
                } else
                    return 0;
            } else
                return 0;
        } else
            return 0;
    } else
        return 0;
    return 0;
}
bool dir_E(int row, int col, int player)
{
    if (board[row][col] == player) {
        if (board[row + 1][col] == player) {
            if (board[row + 2][col] == player) {
                if (board[row + 3][col] == player) {
                    if (board[row + 4][col] == player) {
                        return 1;
                    } else
                        return 0;
                } else
                    return 0;
            } else
                return 0;
        } else
            return 0;
    } else
        return 0;
    return 0;
}
bool dir_NW(int row, int col, int player)
{
    if (board[row][col] == player) {
        if (board[row - 1][col - 1] == player) {
            if (board[row - 2][col - 2] == player) {
                if (board[row - 3][col - 3] == player) {
                    if (board[row - 4][col - 4] == player) {
                        return 1;
                    } else
                        return 0;
                } else
                    return 0;
            } else
                return 0;
        } else
            return 0;
    } else
        return 0;
    return 0;
}
bool dir_NE(int row, int col, int player)
{
    if (board[row][col] == player) {
        if (board[row - 1][col + 1] == player) {
            if (board[row - 2][col + 2] == player) {
                if (board[row - 3][col + 3] == player) {
                    if (board[row - 4][col + 4] == player) {
                        return 1;
                    } else
                        return 0;
                } else
                    return 0;
            } else
                return 0;
        } else
            return 0;
    } else
        return 0;
    return 0;
}
bool dir_SW(int row, int col, int player)
{
    if (board[row][col] == player) {
        if (board[row + 1][col - 1] == player) {
            if (board[row + 2][col - 2] == player) {
                if (board[row + 3][col - 3] == player) {
                    if (board[row + 4][col - 4] == player) {
                        return 1;
                    } else
                        return 0;
                } else
                    return 0;
            } else
                return 0;
        } else
            return 0;
    } else
        return 0;
    return 0;
}
bool dir_SE(int row, int col, int player)
{
    if (board[row][col] == player) {
        if (board[row + 1][col + 1] == player) {
            if (board[row + 2][col + 2] == player) {
                if (board[row + 3][col + 3] == player) {
                    if (board[row + 4][col + 4] == player) {
                        return 1;
                    } else
                        return 0;
                } else
                    return 0;
            } else
                return 0;
        } else
            return 0;
    } else
        return 0;
    return 0;
}

bool checker(int row, int col, int player)
{
    if (dir_N(row, col, player) || dir_S(row, col, player) || dir_W(row, col, player) || dir_E(row, col, player) || dir_NW(row, col, player) || dir_NE(row, col, player) || dir_SW(row, col, player) || dir_SE(row, col, player)) {
        return 1;
    }
    return 0;
}
int main()
{
    int tc;
    cin >> tc;
    while (tc--) {
        int winner = 0;
        for (int i = 1; i <= 19; ++i) {
            for (int j = 1; j <= 19; ++j) {
                cin >> board[i][j];
            }
        }
        for (int i = 1; i <= 19; ++i) {
            for (int j = 1; j <= 19; ++j) {
                if (checker(i, j, 1)) {
                    winner = BLACK;
                } else if (checker(i, j, 2)) {
                    winner = WHITE;
                } else {
                    winner = 0;
                }
                if (winner) {
                    break;
                }
            }
            if (winner) {
                break;
            }
        }
        switch (winner) {
        case 0:
            printf("Yet");
            break;
        case 1:
            printf("Black wins!");
            break;
        case 2:
            printf("White wins!");
            break;
        }
        printf("\n");
    }
    return 0;
}