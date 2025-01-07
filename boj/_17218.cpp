#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Info
{
    string url;
    string pw;
};

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<Info> infos;

    int num_infos, num_pws;
    cin >> num_infos >> num_pws;

    Info temp_Info;
    for (int ti = 0; ti < num_infos; ++ti)
    {
        cin >> temp_Info.url >> temp_Info.pw;
        infos.push_back(temp_Info);
    }
    for (int tp = 0; tp < num_pws; ++tp)
    {
        cin >> temp_Info.url;
        auto result = find_if(infos.begin(), infos.end(), [&temp_Info](const Info &info)
                              { return info.url == temp_Info.url; });

        cout << result->pw << "\n";
    }
}

/*
🔥 알고리즘
그냥 무식하게 데이터를 찾으면 될 것 같다.
더 멋지게 찾고싶으면 알파벳 순으로 정렬해서 이진탐색하면 될 것 같다.

📚 데이터 구조
100,000 짜리 구조체를 만드는 것도 좋아보인다.
*/