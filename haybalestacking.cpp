#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

int main(void){
    int n, k;
    cin >> n >> k;
    int prefix[n];
    fill(prefix, prefix + n, 0);
    for(int i = 0; i < k; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        prefix[b + 1]--;
        prefix[a]++;
    }
    for(int i = 0; i < n; i++){
        if(i){
            prefix[i] += prefix[i - 1];
        }
    }
    sort(prefix, prefix + n);
    cout << prefix[n / 2] << "\n";
    return 0;
}