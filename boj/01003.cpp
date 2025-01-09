// [01003]:피보나치
#include <iostream>
#include <vector>

using namespace std;

// 0의 갯수 1의 갯수를 합산해야하기 때문에
pair<int, int> memo[40];

void recursion(int target)
{
    // 바닥 조건 (우리가 목표하는 값이 이미 존재할 때)
    if (memo[target] != make_pair(0, 0))
    {
        return;
    }

    // 나의 값이 없다면 한 칸 더
    recursion(target - 1);

    // 메모이제이션 판단
    // 이전 값이 있다면 더하고 탈출
    if (memo[target - 1] != make_pair(0, 0))
    {
        memo[target].first = memo[target - 1].first + memo[target - 2].first;
        memo[target].second = memo[target - 1].second + memo[target - 2].second;
        return;
    }
}

int main()
{
    // 초기 메모이제이션;
    memo[0] = make_pair(1, 0);
    memo[1] = make_pair(0, 1);

    int tc;

    cin >> tc;
    for (int i = 0; i < tc; ++i)
    {
        int target;
        cin >> target;
        // cout << "목표값 현재" << memo[target].first << " : " << memo[target].second << '\n';

        recursion(target); // target까지의 0, 1 갯수 구하기

        cout << memo[target].first << " " << memo[target].second << '\n';
    }

    return 0;
}
/*
타겟 값이 n에 대해 n-1 + n-2를 더하면 되는 문제이다.
🔥 알고리즘
비 효율적이다. 재귀를 통해서 높은 값에서 부터 빈 칸을 추적해나가는 것이 더 좋을 것 같다.
*/