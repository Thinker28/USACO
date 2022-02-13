/*
ID: amogh.d1
TASK: sprime
LANG: C++ 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <set>

using namespace std;

int n;
int dx[4] = {1, 3, 7, 9};
set<int> ans;

bool prime(string str){
    int x = stoi(str);
    for(int i = 3; i*i <= x; i+=2){
        if(x % i == 0){
            return false;
        }
    }
    return true;
}
bool check(string str){
    string cur = "";
    bool bad = false;
    for(int i = 0; i < str.length(); i++){
        cur += str[i];
        if(!prime(cur)){
            bad = true;
        }
    }
    return bad == true ? false : true;
}
void dfs(string cur){
    if(cur.length() == n){
        if(check(cur)){
            ans.insert(stoi(cur));
        }
        return;
    }
    for(int i = 0; i < 4; i++){
        dfs(cur + to_string(dx[i]));
    }
}

int main(void){
    ifstream cin("sprime.in");
    ofstream cout("sprime.out");
    cin >> n;
    dfs("2");
    dfs("3");
    dfs("5");
    dfs("7");
    for(auto v: ans){
        cout << v << "\n";
    }
    return 0;
}