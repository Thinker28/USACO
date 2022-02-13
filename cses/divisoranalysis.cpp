#include <iostream>

using namespace std;

int main(void){
    int n;
    cin >> n;
    pair<int, int> base_exp[n];
    for(int i = 0; i < n; i++){
        cin >> base_exp[i].first >> base_exp[i].second;
    }
    int numdivisors = 1;
    for(int i = 0; i < n; i++){
        numdivisors *= (base_exp[i].second + 1);
    }
    int ans = 1;
    for(int i = 0; i < n; i++){
        pair<int, int> xy = base_exp[i];
        int sum = 0;
        for(int j = 0; j <= xy.second; j++){
            sum += pow(xy.first, j);
        }
        ans *= sum;
    }
    int product = numdivisors / 2
    cout << numdivisors << " " << ans << "\n";


    return 0;
}