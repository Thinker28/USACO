#include <iostream>

using namespace std;

int main(void){
    int n, m;
    cin >> n >> m;
    int top = n+m-1;
    int bottom = n-1;
    int top2 = 1;
    for(int i = top; i > top-bottom; i--){
        top2 *= i;
        cout << top2 << "\n";
    }
    cout << top2 / bottom << "\n";
}