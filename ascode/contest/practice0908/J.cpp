// 문제 J: 뱀게임에서 과일 위치 파악하기 - easy
#include <iostream>
using namespace std;

class Point
{
public:
    int x, y;
    Point(int a, int b) : x(a), y(b)
    {
    }
};

string dir(Point sn, Point ap){
    string sol="";
    if(sn.x >= ap.x){ // 사과과 뱀 뒤에
        sol += "PS";
    }else{
        sol += "F";
        if(sn.y > ap.y){ // 뱀 왼쪽
            sol += "L";
        }else if(sn.y<ap.y){ // 뱀 오른쪽
            sol += "R";
        }else{
            sol += "S";
        }
    }
    return sol;
}

int main()
{
    int a[4];
    for(int i = 0; i < 4; ++i){
        cin >> a[i];
    }
    Point snake(a[0],a[1]);
    Point apple(a[2],a[3]);

    cout << dir(snake, apple) << endl;

    return 0;
}
// 연산자 >= 를 >로 변경