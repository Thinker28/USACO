/*
ID: amogh.d1
TASK: namenum
LANG: C++ 
*/
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
using namespace std;

set<string> names;

unordered_set<string> dic;

unordered_map<int, unordered_set<char> > ums; 
void dfs(long long num[], int i, string a, int n){
    if(i == n - 1){
        for(char v: ums[num[i]]){
            if(dic.count(a + v) > 0){
                names.insert(a + v);
            }
        }
        return;
    }
    for(char v: ums[num[i]]){
        dfs(num, i + 1, a + v, n);
    }
}
int main(void){
    ifstream din("dict.txt");
    ifstream cin("namenum.in");
    ofstream cout("namenum.out");
    for(int i = 0; i < 4617; i++){
        string s;
        din >> s;
        dic.insert(s);
    }
    unordered_set<char> us {'A', 'B', 'C'};
    ums[2] = us;
    unordered_set<char> us2 {'D', 'E', 'F'};
    ums[3] = us2;
    unordered_set<char> us3 {'G', 'H', 'I'};
    ums[4] = us3;
    unordered_set<char> us4 {'J', 'K', 'L'};
    ums[5] = us4;
    unordered_set<char> us5 {'M', 'N', 'O'};
    ums[6] = us5;
    unordered_set<char> us6 {'P', 'R', 'S'};
    ums[7] = us6;
    unordered_set<char> us7 {'T', 'U', 'V'};
    ums[8] = us7;
    unordered_set<char> us8 {'W', 'X', 'Y'};
    ums[9] = us8;
    long long a;
    cin >> a;
    long long num[12];
    int i = 0;
    while(a != 0){
      int b = a % 10;
      a /= 10;
      num[i] = b;
      i++;
    }
    reverse(num, num + i);
    dfs(num, 0, "", i);
    if(names.size() == 0){
        cout << "NONE\n";
    }else{
        for(string v: names){
            cout << v << "\n";
        }
    }
    return 0;
}