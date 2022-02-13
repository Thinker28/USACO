/*
ID: amogh.d1
TASK: frac1
LANG: C++ 
*/
#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

int g(int a, int b){
    if (a == 0)
        return b;
    return g(b % a, a);
}
bool cmp(pair<int, int> a, pair<int, int> b){
    return a.first*b.second < a.second*b.first;
}
int main(void){
    ifstream cin("frac1.in");
    ofstream cout("frac1.out");
    set<pair<int, int> > temp;
    vector<pair<int, int> > nums;
    int n;
    cin >> n;
    nums.push_back(make_pair(0, 1));
    for(int num = 1; num <= n; num++){
        for(int den = 1; den <= n; den++){
            if(num > den){
                continue;
            }
            int gcd = g(num, den);
            temp.insert(make_pair((int)num / gcd, (int)den / gcd));
        } 
    }
    for(auto p: temp){
        nums.push_back(p);
    }
    sort(nums.begin(), nums.end(), cmp);
    for(auto p: nums){
        cout << p.first << '/' << p.second << "\n";
    }
    return 0;
}