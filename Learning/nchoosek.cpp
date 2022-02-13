#include <iostream>

using namespace std;

int fac(int a){
    if(a == 1){
        return 1;
    }else{
        return a * fac(a - 1);
    }
}
// int choosefinder(int n, int k){
//     int nFac = 0;
//     nFac += facFinder(n);
//     int kFac = 0;
//     kFac += facFinder(k);
//     int a = n - k;
//     int aFac = facFinder(a);
//     int sum = nFac / (kFac * aFac);
//     return sum;
// }
int main(void){
    int n;
    cout << fac(n) << "\n";

    return 0;
}
//n! / (k!(n-k))!