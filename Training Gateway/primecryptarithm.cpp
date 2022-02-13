/*
ID: amogh.d1
TASK: crypt1
LANG: C++ 
*/
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> l;
bool F(int x){
    while(x){
        bool flag = false;
        int r = x%10;
        x/=10;
        for(int i = 0; i < l.size(); i++){
            if(l[i] == r){
                flag = true;
                break;
            }
        }
        if(!flag){
            return false;
        }
    }
    return true;
}
int main(void){
    ifstream cin("crypt1.in");
    ofstream cout("crypt1.out");
    int n;
    cin >> n;
    l = vector<int> (n);
    for(int i = 0; i < n; i++){
        cin >> l[i];
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                for(int i2 = 0; i2 < n; i2++){
                    for(int j2 = 0; j2 < n; j2++){
                        int a = l[i], b = l[j], c = l[k], d = l[i2], e = l[j2];
                        int f = (100*a+10*b+c)*e;
                        if(F(f) && f < 1000 && f >= 100){
                            int g = (100*a+10*b+c)*d;
                            if(F(g) && g < 1000 && g >= 100){
                                int h = f+10*g;
                                if(F(h) && h < 10000 && h >= 1000){
                                    ans++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}