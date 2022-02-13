#include <iostream>
#include <vector>
using namespace std;

long long n, k;
vector<long long> l;
bool works(long long x){
    long long sum = 0;
    long long groups = 0;
    for(long long i = 0; i < n; i++){
        if(l[i] > x){
            return false;
        }
        if(sum + l[i] > x){
            groups++;
            sum = 0;
        }
        sum += l[i];
    }
    if(sum > 0){
        groups++;
    }
    return groups <= k;
}
int main(void){
    cin >> n >> k;
    l = vector<long long> (n);
    for(long long i = 0; i < n; i++){
        cin >> l[i];
    }
    long long low = 0;
    long long high = 1e18;
    long long ans = -1;   
    while(low <= high){
        long long mid = (low + high) / 2;
        if(works(mid)){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    cout << ans << "\n";
    return 0;
}