#include <iostream>
#include <vector>
#include <unordered_set>
#include <fstream>  
using namespace std;

unordered_set<int> ans;
void friday(int b1milk, vector<int> &b1, vector<int> &b2){
    for(int i = 0; i < b2.size(); i++){
        ans.insert(b1milk + b2[i]);
    }
}
void thursday(int b1milk, vector<int> &b1, vector<int> &b2){
    for(int i = 0; i < b1.size(); i++){
        vector<int> b1_2 = b1;
        vector<int> b2_2 = b2;
        b2_2.push_back(b1[i]);
        b1_2.erase(b1_2.begin() + i);
        friday(b1milk - b1[i], b1_2, b2_2);
    }
}
void wednesday(int b1milk, vector<int> &b1, vector<int> &b2){
    for(int i = 0; i < b2.size(); i++){
        vector<int> b1_2 = b1;
        vector<int> b2_2 = b2;
        b1_2.push_back(b2[i]);
        b2_2.erase(b2_2.begin() + i);
        thursday(b1milk + b2[i], b1_2, b2_2);
    }
}
void tuesday(int b1milk, vector<int> &b1, vector<int> &b2){
    for(int i = 0; i < b1.size(); i++){
        vector<int> b1_2 = b1;
        vector<int> b2_2 = b2;
        b2_2.push_back(b1[i]);
        b1_2.erase(b1_2.begin() + i);
        wednesday(b1milk - b1[i], b1_2, b2_2);
    }
}
int main(void){
    ifstream cin("backforth.in");
    ofstream cout("backforth.out");
    int b1milk = 1000;
    vector<int> b1;
    vector<int> b2;
    for(int i = 0; i < 10; i++){
        int bucket;
        cin >> bucket;
        b1.push_back(bucket);
    }
    for(int i = 0; i < 10; i++){
        int bucket;
        cin >> bucket;
        b2.push_back(bucket);
    }
    tuesday(b1milk, b1, b2);
    cout << ans.size() << "\n";
    return 0;
}