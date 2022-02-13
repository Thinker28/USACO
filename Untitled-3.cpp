/*
ID: amogh.d1
LANG: C++
TASK: gift1
*/

#include <iostream>
#include <unordered_map>
using namespace std;

int main(void){
    int n;
    string name;
    unordered_map<string, int> name_to_amt;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> name;
        name_to_amt[name] = 0;
    }
    string giver, receiver;
    int val, nreceivers;
    for(int i = 0; i < n; i++){
        cin >> giver;
        cin >> val >> nreceivers;
        for(int k = 0; k < n; k++){
            if (giver == names[k]){
                giver_id = k;
                break;
            }
        }
        
        for(int j = 0; j < people; j++){
            cin >> receiver; 
            for(int k = 0; k < n; k++){
                if (receiver == names[k]){
                    receiver_id = k;
                    break;
                }
            }
            // cout << "val: " << (val/people) * people << "\n";
            // cout << "val2: " << val/people << "\n";
            // cout << "name[b3]: " << name[b3] << "\n";
            amt[receiver_id] += (val/people);
            // cout << "name[b2]: " << name[b2] << "\n";
        }
        if (people != 0) {
            amt[giver_id] -= (val/people) * people;
        }
    }
    
    for(int i = 0; i < n; i++){
        cout << names[i] << " " << amt[i] << "\n";
    }

    return 0;
}