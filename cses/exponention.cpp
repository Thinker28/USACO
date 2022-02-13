#include <iostream>

using namespace std;

int power(int a, int b){
    if(b == 0){
        return 1;
    }else if(b == 1){
        return a;
    }
    int val = power(a, b / 2);
    val *= val;
    if(b % 2 == 1){
        val *= a;
    }
    return val;
}
int main(void){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        cout << power(a, b) % 1000000007 << "\n";
    }
    return 0;
}