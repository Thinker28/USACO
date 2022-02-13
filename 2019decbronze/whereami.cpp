#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(void){
    ifstream cin("whereami.in");
    ofstream cout("whereami.out");
    int n;
    cin >> n;
    string a;
    cin >> a;
    vector<string> words;
    int k = 1;
    while(true){
        for(int i = 0; i < n; i++){
            words.push_back(a.substr(i, k));
        }
        bool duplicates = false;
        for(int i = 0; i < words.size(); i++){
            for(int j = 0; j < words.size(); j++){
                if(i == j){
                    continue;
                }else{
                    if(words[i] == words[j]){
                        duplicates = true;
                        break;
                    }
                }
            }
        }
        if(!duplicates){
            break;
        }
        k++;
        words.clear();
    }
    cout << k << "\n";
    return 0;
}