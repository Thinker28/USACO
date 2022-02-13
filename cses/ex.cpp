#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    vector<int> a;
    vector<int> b;
    int target;
    int d;
    while(cin >> d){
        a.push_back(d);
        b.push_back(d);
    }
    int c, e;
    cin >> target;
    sort(a.begin(), a.end());
    int left = 0;
    int right = ((int) a.size()) - 1;
    while(left < right){
        if(left + right > target){
            right--;   
        }else if(left + right < target){
            left++;
        }else if(left + right == target){
            c = a[left];
            e = a[right];
        }
    }
    int pos1, pos2;
    for(int i = 0; i < (int)a.size(); i++){
        if(b[i] == c){
            pos1 = i;
        }else if(b[i] == e){
            pos2 = i;
        }    
    }
    cout << min(pos1, pos2) << max(pos1, pos2) << "\n";
    return 0;
}