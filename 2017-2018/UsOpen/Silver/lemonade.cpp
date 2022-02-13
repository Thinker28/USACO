#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

bool cmp(int a, int b){
    return a > b;
}
int main(void){
    ifstream cin("lemonade.in");
    ofstream cout("lemonade.out");
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr + n, cmp);
    int cows = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] < cows){
            break;
        }else{
            ans++;
            cows++;
        }
    }
    cout << ans << "\n";
    return 0;
}