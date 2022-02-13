#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
#define ll long long
int main(void){
    ll n;
    cin >> n;
    if(n*(n+1)%4 == 0){
        cout << "YES\n";
    }else{
        cout << "NO\n";
        return 0;
    }
    ll n2 = n*(n+1)/4;
    set<ll> ints;
    ll sum = 0;
    for(ll i = n; i >= 1; i--){
        if(sum+i >= n2){
            break;
        }
        sum += i;
        ints.insert(i);
    }
    ll target = n2-sum;
    ints.insert(target);
    cout << ints.size() << "\n";
    for(ll output: ints){
        cout << output << " ";
    }
    cout << "\n";
    vector<ll> output;
    for(ll i = 1; i <= n; i++){
        if(ints.count(i) == 0){
            output.push_back(i);
        }
    }
    cout << output.size() << "\n";
    for(ll elem: output){
        cout << elem << " ";
    }
    return 0;
}