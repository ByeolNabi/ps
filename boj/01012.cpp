// [실버2]:01012,유기농배추
#include <iostream>
#include <vector>

using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void dfs(vector<vector<int>> &field, int w, int h)
{
    // 바닥조건
    // 배추가 없다면 이전 칸으로
    if (field[h][w] == 0)
    {
        return;
    }
    else
    { // 배추가 있으면 뽑아
        field[h][w] = 0;
    }

    // 주변에서 배추 찾기
    for (int i = 0; i < 4; ++i)
    {
        dfs(field, w + dx[i], h + dy[i]);
    }
}

int main()
{

    int tc;
    cin >> tc;
    for (int i = 0; i < tc; ++i)
    {
        int worm_cnt = 0;
        int width, height, cabagge;
        cin >> width >> height >> cabagge; // 가로, 세로

        vector<vector<int>> field(52, vector<int>(52, 0));
        // 배추심기
        for (int j = 0; j < cabagge; ++j)
        {
            int x, y; // 배추 위치, 가로 세로
            cin >> x >> y;
            field[y + 1][x + 1] = 1; // 배추 있다.
        }
        // 벌래 갯수 찾기
        for (int h = 0; h <= height; ++h)
        {
            for (int w = 0; w <= width; ++w)
            {
                if (field[h + 1][w + 1] == 1) // 배추가 있으면 뽑아라
                {
                    dfs(field, w + 1, h + 1);
                    ++worm_cnt;
                }
            }
        }
        cout << worm_cnt << '\n';
    }

    return 0;
}

// 배추를 마주치면 dfs로 다 뽑아버린다고 한다면 밭을 순환하면서 배추를 마주칠때 값을 더하면 된다.
// w, h의 값에 1식 더하면 자동으로 배추 없는 padding이 생겨서 1씩 더함
// -> padding을 잘못 이해해서 For문 순환에서 1부터 시작했음 : 0으로 수정