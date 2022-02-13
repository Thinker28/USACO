#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long
ll binSearch(vector<ll> &vec, ll size, ll searchVal){
    int low = 0;
    int high = size - 1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(searchVal < vec[mid]){
            high = mid - 1;
        }else if(searchVal > vec[mid]){
            low = mid + 1;
        }else if(searchVal == vec[mid]){
            return mid;
        }
    }
    return -1;
}
int main(void){
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> arr;
    vector<ll> arr2;
    for(ll i = 0; i < n; i++){
        ll a;
        cin >> a;
        arr.push_back(a);
        arr2.push_back(a);
    }
    bool works = false;
    for(int i = 0; i < n && !works; i++){
        for(int j = i + 1; j < n && !works; j++){
            ll elem = x - (arr[i] + arr[j]);
            ll a = binSearch(arr2, n, elem);
            ll b;
            if(a != -1){
                b = arr2[a];
            }
            ll d;
            if(a != -1){
                works = true;
            }
            if(a != -1 && d != i && d != j){
                cout << i + 1 << " " << j + 1 << " " << d + 1 << "\n";
                return 0;
            }

        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}