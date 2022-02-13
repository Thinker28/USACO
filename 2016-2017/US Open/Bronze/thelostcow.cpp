#include <iostream>
#include <fsZ
using namespace std;

int main(void){
    ifstream cin("lostcow.in");
    ofstream cout("lostcow.out");
    int x, y;
    cin >> x >> y;
    int pos = x;
    int goal = 1;
    int distance = 0;
    while(true){
        if((x + goal <= y && y < x) || (x < y && x + goal >= y)){
            distance += abs(y - pos);
            break;
            //
        }else{
            distance += abs(x + goal - pos);
            pos = x + goal;
            goal *= -2;
        }
    }
    cout << distance;
    return 0;
}