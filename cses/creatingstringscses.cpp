#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    string a;
    cin >> a;
    sort(a.begin(), a.end());
    vector<char> permu;
    vector<string> ans;
    for(int i = 0; i < (int)a.length(); i++){
        permu.push_back(a[i]);
    }
    do{
        string b;
        for(int i = 0; i < (int)permu.size(); i++){
            b += permu[i];  
        }
        if(b == a){
            continue;
        }else{
            ans.push_back(b);
            b = "";
        }
    }while(next_permutation(permu.begin(), permu.end()));
    cout << (int)ans.size() + 1 << "\n";
    cout << a << "\n";
    for(int i = 0; i < (int)ans.size(); i++){
        cout << ans[i] << "\n";
    }
    return 0;
}