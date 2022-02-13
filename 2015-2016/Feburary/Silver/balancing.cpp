#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

#define f first
#define s second
int main(void){
    ifstream cin("balancing.in");
    ofstream cout("balancing.out");
    int n;
    cin >> n;
    pair<int, int> points[n];
    for(int i = 0; i < n; i++){
        cin >> points[i].f >> points[i].s;
    }
    sort(points, points + n);
    int ans = 1e9;
    for(int i = 0; i < n - 1; i++){
        int x = points[0].f;
        int y = points[i].s;
        int ll = 0, lr = 0, ul = 0, ur = 0;
        for(int j = 0; j < n; j++){
            if(points[j].s > y){
                ur++;
            }else{
                lr++;
            }
        }
        ans = min(ans, max(max(ll, lr), max(ul, ur)));
        for(int j = 0; j < n; j++){
            if(points[j].s > y){
                ur--;
                ul++;
            }else if(points[j].s < y){
                lr--;
                ll++;
            }
            ans = min(ans, max(max(ll, lr), max(ul, ur)));
        }
    }
    cout << ans << "\n";
    return 0;
}