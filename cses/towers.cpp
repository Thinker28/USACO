#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<int> stacktop;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        auto it = upper_bound(stacktop.begin(), stacktop.end(), a);
        if(it == stacktop.end()){
            stacktop.push_back(a);
        }else{
            stacktop[it - stacktop.begin()] = a;
        }
    }
    cout << stacktop.size() << "\n";
    return 0;
}