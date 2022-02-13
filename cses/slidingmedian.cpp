#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
int main(void){
    int n, k;
    cin >> n >> k;
    vector<int> vec;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        vec.push_back(a);
    }
    vector<int> tmp;
    for(int i = 0; i < k; i++){
        tmp.push_back(vec[i]);
    }
    vector<int> tmp2;
    tmp2 = tmp;
    sort(tmp2.begin(), tmp2.end());
    if(k % 2 == 1){
        cout << tmp2[(k/2)] << " ";
    }else{
        cout << tmp2[(k/2) - 1] << " ";
    }
    cout << "\n";
    tmp2.clear();
    for(int i = k; i < n; i++){
        tmp.erase(tmp.begin());
        // for(int j = 0; j < tmp.size(); j++){
        //     cout << tmp[i] << " ";
        // }
        
        auto it = upper_bound(tmp.begin(), tmp.end(), vec[i]);
        if(it == tmp.begin()){
            auto it2 = (tmp.begin() + tmp.size());
            tmp.insert(it2, vec[i]);
        }else if(it - tmp.begin() == 0){
            tmp.insert(it, vec[i]);        
        }else{
            tmp.insert(it, vec[i]);
        }
        cout << "i: " << i << "\n" << it - tmp.begin() << "\n";
        for(int j = 0; j < tmp.size(); j++){
            cout << tmp[j] << " "; 
        }
        cout << "\n";
        if(k % 2 == 1){
            cout << tmp[(k/2)] << " ";
        }else{
            cout << tmp[(k/2) - 1] << " ";
        }
        cout << "\n";
    }
    return 0;
}
