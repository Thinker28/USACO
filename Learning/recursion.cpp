#include <iostream>


using namespace std;


int fibNum(int a){
    if (a == 1 || a == 2) {
        // cout << "base case: " << a << "\n";
        return 1;
    }
    
    else {
        // cout << "in fibNum(" << a << "), left: calling fibNum(" << a - 1 << ")\n";
        int left =  fibNum(a - 1);
        // cout << "in fibNum(" << a << "), left left: calling fibNum(" << a - 2 << ")\n";
        int leftleft = fibNum(a - 2);
        return left + leftleft;
    }
}

int main(void){
    int n;
    cin >> n;
    // cout << "in main: calling fibNum(" << n << ")\n";
    cout << fibNum(n) << "\n";
    return 0;
}