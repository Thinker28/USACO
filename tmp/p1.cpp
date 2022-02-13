#include <iostream>
#include <algorithm>
#include <fstream>
#include <map>
#include <set>
using namespace std;

struct Log{
    int amt;
    string name;
};
bool cmp(Log l1, Log l2){
    return l1.amt < l2.amt;
}
Log amtarr[7];
int main(void){
    ifstream cin("notlast.in");
    ofstream cout("notlast.out");
    int n;
    cin >> n;
    set<string> possible;
    map<string, int> m;
    m["Bessie"] = 0;
    m["Elsie"] = 1;
    m["Daisy"] = 2;
    m["Gertie"] = 3;
    m["Annabelle"] = 4;
    m["Maggie"] = 5;
    m["Henrietta"] = 6;
    for(int i = 0; i < n; i++){
        string name2;
        int amt2;
        cin >> name2 >> amt2;
        possible.insert(name2);
        amtarr[m[name2]].amt += amt2;
        amtarr[m[name2]].name = name2;
    }
    sort(amtarr, amtarr + 7, cmp);
    int pastamt = amtarr[0].amt;
    int i = 0;
    while(amtarr[i].amt == pastamt){
        i++;
    }
    if(n == 1){
        cout << amtarr[i].name << "\n";
        return 0;
    }
    set<int> past;
    bool tie = true;
    for(auto v: possible){
        if(past.count(amtarr[m[v]].amt) == 0 && past.size() != 0 && amtarr[m[v]].amt != 0){
            tie = false;
        }
        if(amtarr[m[v]].amt != 0){
            past.insert(amtarr[m[v]].amt);
        }
        
    }
    if(tie){
        cout << "Tie\n";
        return 0;
    }
    cout << amtarr[i].name << "\n";
}