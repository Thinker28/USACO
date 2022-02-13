#include <iostream>
#include <fstream>
#include <unordered_set>
using namespace std;

#define ll long long
int main(void){
    // ifstream cin("cowrow.in");
    // ofstream cout("cowrow.out");
    int n;
    cin >> n;
    ll arr[n];
    unordered_set<ll> removal;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        removal.insert(arr[i]);
    }
    int max2 = -1;
    for(int v: removal){
        int count = 1;
        for(int i = 0; i < n - 1; i++){
            if(arr[i] == v){
                continue;
            }else{
                if(arr[i] == arr[i + 1]){
                    count++;
                }else{
                    count = 1;
                }
            }
        }
        max2 = max(max2, count);
    }
    cout << max2 << "\n";
    return 0;
}