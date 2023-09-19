//1001: 나는 차차를 싫어해!
#include <iostream>
using namespace std;

int main()
{
    int tc = 0;
    cin >> tc;
    for (int i = 0; i < tc; ++i)
    {
        // 입력받는 문자열
        string input_str;
        cin >> input_str;

        // char가 없는 문자열 저장하는 변수;
        string no_char = "";
        // char 갯수
        int counter = 0;

        // char Comparator
        for (int i = 0; i < input_str.length(); ++i)
        {
            if (input_str[i] == 'c' && i < input_str.length() - 3)
            {
                if (input_str[i + 1] == 'h' && input_str[i + 2] == 'a' && input_str[i + 3] == 'r')
                {
                    // if true => up counter
                    ++counter;
                    i += 3; // char는 스킵하기
                }
            }
            else
            {
                // char가 없다면 더해나가
                no_char += input_str[i];
            }
        }

        // 출력 경우의 수 나누기
        if (counter > 1)
        {
            if (no_char == ""){
                cout << "I Hate CharChar!" << endl;
            } else{
               cout << no_char << endl;
            }
        }
        else{
            if (input_str == "")
            {
                cout << "I Hate CharChar!" << endl;
            } else{
                cout << input_str << endl;
            }
        }
    }

    return 0;
}