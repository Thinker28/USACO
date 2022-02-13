#include <iostream>
#include <fstream>
using namespace std;

int main(void){
    // ifstream cin("mountains.in");
    // ofstream cout("mountains.out");
    int n;
    cin >> n;
    pair<int, int> xy[n];
    for(int i = 0; i < n; i++){
        cin >> xy[i].first >> xy[i].second;
    }
    int cnt = 0;
    bool seen[n];
    fill(seen, seen + n, true);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j){
                continue;
            }
            int a = xy[i].first - xy[i].second;
            int b = xy[i].first + xy[i].second;
            int c = xy[j].first - xy[j].second;
            int d = xy[j].first + xy[j].second;
            
            if(e > 0){
                seen[i] = false;

            }
        }
    }
    
    for(int i = 0; i < n; i++){
        if(!seen[i]){
            cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}