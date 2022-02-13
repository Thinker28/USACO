#include <iostream>
#include <cmath>
using namespace std;

int main(void){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        int d = b * c;
        for(int i = 0; i < d; i++){
            a *= a;
        }
        cout << a << "\n";
    }
    return 0;
}