#include <iostream>
#include <algorithm>
using namespace std;

bool check(pair<int, int> p[], int n){
    for(int i = 0; i < n - 1; i++){
        if(p[i].second > p[i+1].second){
            return false;
        }
    }
    return true;
}
int main(void){
    int t;
    cin >> t;
    for(int t1 = 0; t1 < t; t1++){
        int n;
        cin >> n;
        pair<int, int> p[n];
        for(int i = 0; i < n; i++){
            cin >> p[i].first >> p[i].second;
        }
        sort(p, p + n);
        if(!check(p, n)){
            cout << "NO\n";
            continue;
        }
        string path = "";
        int x, y;
        x = 0;
        y = 0;
        for(int i = 0; i < n; i++){
            for(int j = x; j < p[i].first; j++){
                path += 'R';
            }
            for(int j = y; j < p[i].second; j++){
                path += 'U';
            }
            x = p[i].first;
            y = p[i].second;
        }
        cout << "YES\n";
        cout << path << "\n";
    }

    return 0;
}