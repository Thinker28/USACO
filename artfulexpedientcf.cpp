#include <iostream>
#include <unordered_set>
using namespace std;

int main(void){
    int n;
    cin >> n;
    int x[n];
    int y[n];
    unordered_set<int> nums;
    for(int i = 0; i < n; i++){
        cin >> x[i];
        nums.insert(x[i]);
    }
    for(int i = 0; i < n; i++){
        cin >> y[i];
        nums.insert(y[i]);
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(nums.count(x[i] ^ y[j]) > 0){
                ans++;
            }
        }
    }
    cout << (ans % 2 == 0 ? "Karen\n" : "Koyomi\n"); 
    return 0;
}