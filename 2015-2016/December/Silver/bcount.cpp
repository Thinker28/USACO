#include <iostream>
#include <fstream>
using namespace std;

int main(void){
    ifstream cin("bcount.in");
    ofstream cout("bcount.out");
    int n, q;
    cin >> n >> q;
    int h[n];
    int g[n];
    int j[n];
    int pasth = 0;
    int pastg = 0;
    int pastj = 0;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        if(a == 1){
            h[i] = pasth + 1;
            g[i] = pastg;
            j[i] = pastj;
            pasth++;
        }else if(a == 2){
            h[i] = pasth;
            g[i] = pastg + 1;
            j[i] = pastj;
            pastg++;
        }else if(a == 3){
            h[i] = pasth;
            g[i] = pastg;
            j[i] = pastj + 1;
            pastj++;
        }
    }
    // for(int i = 0; i < n; i++){
    //     cout << "\n" << h[i] << " " << g[i] << " " << j[i] << "\n";
    // }
    for(int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        if(a - 1 < 0){
            cout << h[b] << " " << g[b] << " " << j[b] << "\n";
        }else{
            cout << h[b] - h[a - 1] << " " << g[b] - g[a - 1] << " " << j[b] - j[a - 1] << "\n";
        }
    }
    return 0;
}