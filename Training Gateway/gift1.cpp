/*
ID: amogh.d1
LANG: C++11
TASK: gift1
*/

#include <fstream>
#include <string>
using namespace std;

#define MAXN 15
int amt[MAXN];
string names[MAXN];

int main(void){
    ifstream cin("gift1.in");
    ofstream cout("gift1.out");

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> names[i];
        amt[i] = 0;
    }
    string giver, receiver;
    int val, people, giver_id, receiver_id;
    for(int i = 0; i < n; i++){
        cin >> giver;
        cin >> val >> people;
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