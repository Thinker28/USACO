#include <iostream>

using namespace std;

int sum(int a){
    int sum2 = 0;
    // if(a == 1){
    //     return 1;
    // }else{
    //     return a + sum(a - 1);
    // }
    for(int i = 0; i < a; i++){
        sum2 += a - i;
    }
    return sum2;
}

int main(void){
    int n;
    cin >> n;

    cout << sum(n) << "\n";
    return 0;
}