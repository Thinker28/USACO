#include <iostream>
#include <fstream>

using namespace std;

int signs[100001];
int p[100001];
int main(void){
    ifstream cin("maxcross.in");
    ofstream cout("maxcross.out");
    int n, k, b;
    cin >> n >> k >> b;
    for(int i = 0; i < b; i++){
        int signal;
        cin >> signal;
        signs[signal]++;
    }
    for(int i = 0; i < n; i++){
        p[i + 1] = p[i] + signs[i + 1]; 
    }
    long long ans = 1e18;
    for(int i = 0; i <= n - k; i++){
        ans = min(ans, (long long)p[i + k] - p[i]);
    }
    cout << ans << "\n";
    return 0;
}