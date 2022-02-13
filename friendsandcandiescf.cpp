#include <iostream>
#include <vector>
using namespace std;

int main(void){
    int t;
    cin >> t;
    vector<int> vec;
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
            int b;
            cin >> b;
            vec.push_back(b);
        }
        
        vec.erase(vec.begin(), vec.end());
    }


    return 0;
}