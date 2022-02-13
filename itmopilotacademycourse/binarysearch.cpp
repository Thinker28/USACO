#include <iostream>
#include <vector>
using namespace std;

#define ll long long
bool binSearch(vector<ll> &vec, ll size, ll searchVal){
    int low = 0;
    int high = size - 1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(searchVal < vec[mid]){
            high = mid - 1;
        }else if(searchVal > vec[mid]){
            low = mid + 1;
        }else if(searchVal == vec[mid]){
            return true;
        }
    }
    return false;
}
int main(void){
    ll n, k;
    cin >> n >> k;
    vector<ll> vec;
    
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        vec.push_back(a);
    }
    for(int i = 0; i < k; i++){
        int searchVal;
        cin >> searchVal;
        if(binSearch(vec, n, searchVal)){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }

    return 0;
}