/*
    ans: 1. p[i] = # prefixes = i, hence ans = (i choose 2) = i*(i-1)/2
        2. p[i] = sum, loop through prefixes, check if remainder was a valid prefix remainder, ans += that
        Account for negative numbers, by doing m[((l % n) + n)%n]
*/
//1
#include <iostream>
#include <map>
using namespace std;

int main(void){
    int n;
    cin >> n;
    map<long long, long long> m;
    m[0] = 1;
    long long prefix = 0;
    for(int i = 0; i < n; i++){
        int l;
        cin >> l;
        prefix += l;
        //same remainder except positive
        m[((prefix % n) + n) % n]++;
    }
    long long ans = 0;
    for(auto y: m){
        long long x = y.second;
        ans += (x * (x - 1)) / 2;
    }
    cout << ans << "\n";
    return 0;
}