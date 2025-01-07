#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    unordered_map<string, string> infos;

    int num_infos, num_pws;
    cin >> num_infos >> num_pws;

    string url, pw;
    for (int ti = 0; ti < num_infos; ++ti)
    {
        cin >> url >> pw;
        infos[url] = pw;
    }
    for (int tp = 0; tp < num_pws; ++tp)
    {
        cin >> url;
        cout << infos[url] << "\n";
    }
}

/*
🔥 알고리즘
그냥 무식하게 데이터를 찾으면 될 것 같다.
더 멋지게 찾고싶으면 알파벳 순으로 정렬해서 이진탐색하면 될 것 같다.

📚 데이터 구조
100,000 짜리 구조체를 만드는 것도 좋아보인다.

⛔️ 실패   
시간초과가 되었다.
-> 뭔가를 찾는 것에서는 dictionary자료구조를 항상 생각하자
*/