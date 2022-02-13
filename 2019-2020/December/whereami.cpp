#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main(void){
    ifstream cin("whereami.in");
    ofstream cout("whereami.out");
    int n;
    string s;
    cin >> n >> s;
    vector<string> vec;
    int k = 1;
    while(true){
        for(int i = 0; i < n; i++){
            vec.push_back(s.substr(i, k));
        }
        bool duplicates = false;
        // cout << (int)vec.size() << "\n";
        for(int i = 0; i < (int)vec.size(); i++){
            for(int j = 0; j < (int)vec.size(); j++){
                if(i == j){
                    continue;
                }else{
                    if(vec[i] == vec[j]){
                        duplicates = true;
                    }
                }
            }
        }
        if(duplicates){
            k++;
            vec.clear();
        }else if(!duplicates){
            break;
        }
    }
    cout << k << "\n";
    return 0;
}