#include <iostream>
#include <fstream>
using namespace std;

int prefixh[100000], prefixp[100000], prefixs[100000];
int main(void){
    ifstream cin("hps.in");
    ofstream cout("hps.out");
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        char a;
        cin >> a;
        if(i == 0){
            if(a == 'H'){
                prefixh[i] = 1;
                prefixs[i] = 0;
                prefixp[i] = 0;
            }else if(a == 'P'){
                prefixh[i] = 0;
                prefixs[i] = 0;
                prefixp[i] = 1;
            }else{
                prefixh[i] = 0;
                prefixs[i] = 1;
                prefixp[i] = 0;
            }
            continue;
        }
        if(a == 'H'){
            prefixh[i] = prefixh[i - 1] + 1;
            prefixs[i] = prefixs[i - 1];
            prefixp[i] = prefixp[i - 1];
        }else if(a == 'P'){
            prefixh[i] = prefixh[i - 1];
            prefixs[i] = prefixs[i - 1];
            prefixp[i] = prefixp[i - 1] + 1;
        }else{
            prefixh[i] = prefixh[i - 1];
            prefixs[i] = prefixs[i - 1] + 1;
            prefixp[i] = prefixp[i - 1];
        }
    }
    // for(int i = 0; i < n; i++){
    //     cout << prefixh[i] << " " << prefixs[i] << " "  << prefixp[i] << "\n";
    // }
    int ans = -1;
    for(int split = 0; split <= n; split++){
        int beforesplit = max(max(prefixh[split], prefixs[split]), prefixp[split]);
        int afterSplit = max(max(prefixh[n - 1] - prefixh[split], prefixs[n - 1] - prefixs[split]), prefixp[n - 1] - prefixp[split]);
        // cout << beforesplit << " " << afterSplit << "\n";
        ans = max(ans, beforesplit + afterSplit);
    }
    cout << ans << "\n";
    return 0;
}