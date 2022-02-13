/*
ID: amogh.d1
LANG: C++14
TASK: gift1
*/

#include <iostream>
#include <unordered_map>
using namespace std;

int main(void){
    int n;
    unordered_map<string, int> name_to_amt;
    string names[10];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> names[i];
        name_to_amt[names[i]] = 0;
    }
    string giver, receiver;
    int val, nreceivers;
    for(int i = 0; i < n; i++){
        cin >> giver >> val >> nreceivers;

        for(int j = 0; j < nreceivers; j++){
            cin >> receiver;
            name_to_amt[receiver] += val / nreceivers;
        }

        if (nreceivers != 0) {
            name_to_amt[giver] -= (val / nreceivers) * nreceivers;
        }
    }
    
    for (int i = 0; i < n; i++) {
        cout << names[i] << " " << name_to_amt[names[i]] << "\n";
    }

    return 0;
}