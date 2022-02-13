/*
ID: amogh.d1
TASK: beads
LANG: C++ 
*/
#include <iostream>
#include <fstream>
using namespace std;

int right(int idx, string s){
    char color = s[idx];
    int i = idx;
    while(s[i] == 'w'){
        i++;
        color = s[i % s.length()];
    }
    char current = s[idx];
    int count = 0;
    while(current == color || current == 'w'){
        count++;
        idx = (idx + 1) % s.length();
        current = s[idx];
    }
    return count;
}

int left(int idx, string s){
    int count = 0;
    char color = s[idx];
    int i = idx;
    while(s[i] == 'w'){
        color = s[i];
        i = ((i - 1 + s.length()) % s.length());
    }
    char current = s[idx];
    while(current == color || current == 'w'){
        count++;
        idx = (idx - 1 + s.length()) % s.length();
        current = s[idx];
    }
    return count;
}
int main(void){
    ifstream cin("beads.in");
    ofstream cout("beads.out");
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool blue = true;
    bool red = true;
    for(int i = 0; i < n; i++){
        if(s[i] == 'r'){
            blue = false;
        }else if(s[i] == 'b'){
            red = false;
        }
    }
    if(red || blue){
        cout << n << "\n";
        return 0;
    }
    int ans = 1;
    for(int split = 0; split < n; split++){
        ans = max(ans, left(split, s) + right(split + 1, s));
    }
    cout << ans << "\n";
    return 0;
}