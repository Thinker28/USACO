#include <iostream>
#include <vector>
using namespace std;

#define ll long long
int binSearch(vector<ll> &vec, ll size, ll searchVal){
    int low = 0;
    int high = size - 1;
    while(high > low + 1){
        int mid = (low + high) / 2;
        if(searchVal >= vec[mid]){
            low = mid;
        }else{
            high = mid;
        }
    }
    return high;
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
        cout << binSearch(vec, n, searchVal);
    }

    return 0;
}