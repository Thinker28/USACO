#include <iostream>

using namespace std;

int main(void){
    int n;
    cin >> n;
    cout << n << " ";
    while(n != 1){
        if(n % 2 == 0){
            n /= 2;
        }else if(n % 2 != 0){
            n = (n * 3) + 1;
        }
        cout << n << " ";
    }
    return 0;
}