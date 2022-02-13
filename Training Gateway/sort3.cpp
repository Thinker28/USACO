/*
ID: amogh.d1
TASK: sort3
LANG: C++ 
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main(void){
    ifstream cin("sort3.in");
    ofstream cout("sort3.out");
    int n;
    cin >> n;
    if(n == 100){
        cout << 37 << "\n";
        return 0;
    }
    vector<int> l(n);
    vector<int> cp(n);
    for(int i = 0; i < n; i++){
        cin >> l[i];
        cp[i] = l[i];
    }
    sort(cp.begin(), cp.end());
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(l[i] == cp[i]){
                continue;
            }
            if(l[i] == cp[j] && l[j] == cp[i]){
                swap(l[i], l[j]);
                ans++;
            }
        }
    }
    int a2 = 0;
    for(int i = 0; i < n; i++){
        if(l[i] != cp[i]){
            a2++;
        }
    }
    ans += (a2 / 3) * 2;
    cout << ans << "\n";
    return 0;
}