#include <iostream>
using namespace std;

int main(){
    int q[101] ={0};
    int size, cases;
    cin >> size >> cases;
    for(int cmd = 0; cmd < cases; ++cmd){
        int start, end, number;
        cin >> start >> end >> number;
        for(int s = start; s <= end; ++s){
            q[s] = number;
        }
    }
    for(int s = 1; s <= size; ++s){
        printf("%d ", q[s]);
    }
    printf("\n");
    return 0;
}