#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long
int main(void){
    ll n, x;
    cin >> n >> x;
    ll arr[n];
    vector<ll> vec;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        vec.push_back(arr[i]);
    }
    bool possible = false;
    sort(arr, arr + n);
    ll a, b;
    ll left = 0;
    ll right = n - 1;
    while(left < right){
        if(arr[left] + arr[right] > x){
            right--;
        }else if(arr[left] + arr[right] < x){
            left++;
        }else if(arr[left] + arr[right] == x){
           possible = true;
           a = arr[left];
           b = arr[right];
           break; 
        }
    }
    ll pos1, pos2;
    bool visited[n];
    fill(visited, visited + n, false);
    if(a == b){
        for(ll i = 0; i < n; i++){
            if(a == vec[i]){
                pos1 = i + 1;
                visited[i] = true;
                // vec.erase(vec.begin() + i);
                break;
            }
        }
        for(ll i = 0; i < n; i++){
            if(b == vec[i] && !visited[i]){
                pos2 = i + 1;
                break;
            }
        }
    }else{
        for(ll i = 0; i < n; i++){
            if(vec[i] == a){
                pos1 = i + 1;
            }else if(vec[i] == b){
                pos2 = i + 1;
            }
        }
    }
    if(!possible){
        cout << "IMPOSSIBLE" << "\n";
    }else{
        cout << pos1 << " " << pos2 << "\n";
    }
    
    return 0;
}
