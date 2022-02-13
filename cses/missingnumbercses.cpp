#include <iostream>

#define ll long long
using namespace std;

int main(void){
    ll n;
    cin >> n;
    ll arr[n];
    bool visited[n];
    for(int i = 0; i < n; i++){
        visited[i] = false;
    }
    for(int i = 0; i < n - 1; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < n - 1; i++){
        visited[arr[i] - 1] = true;
    }
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            cout << i + 1 << "\n";
        }
    }
    return 0;
}