/*
ID: amogh.d1
TASK: milk2
LANG: C++ 
*/
#include <iostream>
#include <fstream>
using namespace std;

bool intreval[1000000];
#define f first
#define s second
int main(void){
    ifstream cin("milk2.in");
    ofstream cout("milk2.out");
    int n;
    cin >> n;
    pair<int, int> p[n];
    int maxC = 0;
    int minC = 1e9;
    for(int i = 0; i < n; i++){
        cin >> p[i].f >> p[i].s;
        maxC = max(p[i].s, maxC);
        minC = min(p[i].f, minC);
    }
    for(int i = 0; i < n; i++){
        for(int j = p[i].f; j < p[i].s; j++){
            intreval[j] = true;
        }
    }
    int longest = 0;
    int shortest = 0;
    int ans1 = 0;
    int ans2 = 0;
    for(int i = minC; i < maxC; i++){
        if(intreval[i]){
            longest++;
            ans2 = max(ans2, shortest);
            ans1 = max(ans1, longest);
            shortest = 0;            
        }else{
            shortest++;
            ans1 = max(ans1, longest);
            ans2 = max(ans2, shortest);
            longest = 0;
        }
    }
    cout << ans1 << " " << ans2 << "\n";
    return 0;
}