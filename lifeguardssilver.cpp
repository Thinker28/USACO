#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <array>    

using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<array<int, 3> > times;
    for(int i = 0; i < n; i++){
        int start, end;
        cin >> start >> end;
        times.push_back({start, i, 1});
        times.push_back({end, i, -1});
    }
    sort(times.begin(), times.end());
    int last = 0;
    set<int> working;
    int amt[n];
    for(array<int, 3> a: times){
        if(working.size() == 1){
            amt[*working.begin()] += amt[] 
        }
    }
    return 0;
}