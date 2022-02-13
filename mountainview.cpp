#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
#define ll long long

struct Mountain{
    ll left;
    ll right;
};
bool cmp(Mountain a, Mountain b){
    if(a.left == b.left){
        return a.right > b.right;
    }
    return a.left < b.left;
}

Mountain Mountains[100000];
int main(void){
    ifstream cin("mountains.in");
    ofstream cout("mountains.out");
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        Mountains[i].left = x - y;
        Mountains[i].right = x + y;
    }
    int ans = 0;
    int maxright = -1;
    sort(Mountains, Mountains + n, cmp);
    for(int i = 0; i < n; i++){
        if(Mountains[i].right > maxright){
            maxright = Mountains[i].right;
            ans++;
        }
        
    }
    cout << ans << "\n";
    return 0;
}