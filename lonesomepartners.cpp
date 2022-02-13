#include <iostream>

using namespace std;

int main(void){
    int n;
    cin >> n;
    int x[n];
    int y[n];
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }
    int maxD = -1;
    int x2, y2;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j){
                continue;
            }
            int a = (x[j] - x[i]) * (x[j] - x[i]);
            int b = (y[j] - y[i]) * (y[j] - y[i]);
            if(a + b > maxD){
                x2 = i + 1;
                y2 = j + 1;
                maxD = a + b;
            }
        }
    }
    cout << x2 << " " << y2 << "\n";
    return 0;
}