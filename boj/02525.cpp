#include<iostream>
using namespace std;

class oven_clock{
private:
    int time;
public:
    void set(int h, int m){
        time = h*60 + m;
    }
    void print(){
        printf("%d %d\n",(time/60)%24,time%60);
    }
    void add(int t){
        time += t;
    }
};

int main(){
    oven_clock oven;
    int h,m; cin >> h >> m;
    oven.set(h,m);
    cin >> m;
    oven.add(m);
    oven.print();
    return 0;
}