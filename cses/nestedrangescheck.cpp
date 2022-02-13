#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b){
    return a.first < b.first;
}
int main(void){
    int n;
    cin >> n;
    pair<int, int> p[n];
    for(int i = 0; i < n; i++){
        cin >> p[i].first >> p[i].second;
    }
    sort(p, p + n, cmp);
    int arr[n];
    for(int i = 0; i < n; i++){
        if(p[i + 1].first > p[i].first && p[i + 1].second < p[i].second){
            //p[i] is nesting p[i + 1]
            
        }
    }
    return 0;
}