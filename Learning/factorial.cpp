#include <iostream>

using namespace std;

int fac(int a){
    if(a == 1){
        return 1;
    }else{
        return a * fac(a - 1);
    }
}
int main(void){
    int n;
    cin >> n;
    int x[n];
    int y[n];
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }
    for(int i = 0; i < n; i++){
        int a = x[i];
        int b = y[i];
        cout << fac(a) / (fac(b) * fac(a - b)) << "\n";
    }
    return 0;
}