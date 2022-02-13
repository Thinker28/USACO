#include <iostream>

using namespace std;

#define f first
#define s second
bool cmp(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}

int main(void){
    int n;
    cin >> n;
    pair<int, int> p[n];
    for(int i = 0; i < n; i++){
        cin >> p[i].f >> p[i].s;
    }
    sort(p, p + n, cmp);
    int rooms[n];
    int ans = 0;
    int past = 1;
    for(int i = 1; i < n; i++){
        if(p[i].f < p[i - 1].s){
            ans++;
            rooms[i] = past + 1;
            past++;
        }else{
            
        }
    }
    return 0;
}