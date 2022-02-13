 #include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

const int MAXN = 8;
int adj[MAXN][MAXN];
int adj2[MAXN][MAXN];
vector<string> vec;
map<string, int> map1;
int main(void){
    int n;
    cin >> n;
    vec.push_back("Beatrice");
    vec.push_back("Belinda");
    vec.push_back("Bella");
    vec.push_back("Bessie");
    vec.push_back("Betsy");
    vec.push_back("Blue");
    vec.push_back("Buttercup");
    vec.push_back("Sue");
    
    map1.insert(make_pair("Beatrice", 0));
    map1.insert(make_pair("Belinda", 1));
    map1.insert(make_pair("Bella", 2));
    map1.insert(make_pair("Bessie", 3));
    map1.insert(make_pair("Betsy", 4));
    map1.insert(make_pair("Blue", 5));
    map1.insert(make_pair("Buttercup", 6));
    map1.insert(make_pair("Sue", 7));
    // map<string,int>::iterator it;
    map<string,int>::iterator it2;
    map<string, int>::iterator it3;
    map<string, int>::iterator it4;
    map<string, int>:: iterator it5;

    for(int i = 0; i < n; i++){
        int pos1, pos2;
        string name1, name2, trash;
        cin >> name1 >> trash >> trash >> trash >> trash >> name2;
        adj[map1[name1]][map1[name2]]++;
        adj[map1[name2]][map1[name1]]++;
    }

    int counter = 0;
   
    do{
        for(int i = 0; i < 8; i++){
            if(i == 0){
                it3 = map1.find(vec[i]);
                it4 = map1.find(vec[i + 1]);
                if(adj2[it3->second][it4->second] == 0){
                    adj2[it3->second][it4->second]++;
                }
            }else if(i != 0 && i == 7){
                it3 = map1.find(vec[i]);
                it4 = map1.find(vec[i - 1]);
                if(adj2[it3->second][it4->second] == 0){
                    adj2[it3->second][it4->second]++;
                }
            }else{
                it3 = map1.find(vec[i - 1]);
                it4 = map1.find(vec[i]);
                it5 = map1.find(vec[i + 1]);
                if(adj2[it3->second][it4->second] == 0){
                    adj2[it3->second][it4->second]++;
                }
                if(adj2[it4->second][it5->second] == 0){
                    adj2[it4->second][it5->second]++;
                }
            }
        }
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                // cout << "adj2: " << adj2[i][j] << " ";
                if(adj2[i][j] == adj[i][j]){
                    counter++;
                }
            }
        }
        // cout << "\n";
        // for(int i = 0; i < 7; i++){
        //     for(int j = 0; j < 7; j++){
        //         cout << "adj: " << adj[i][j] << " ";
        //         // if(adj2[i][j] == adj[i][j]){
        //         //     counter++;
        //         // }
        //     }
        // }
        // cout << "\n";

        if(counter == n){
            for(int i = 0; i < 8; i++){
                cout << vec[i] << "\n";
            }
            return 0;
        }else{
            counter -= counter;
            for(int i = 0; i < 8; i++){
                for(int j = 0; j < 8; j++){
                    adj2[i][j] = 0;
                }
            }
        }
    }while(next_permutation(vec.begin(), vec.end()));
    
    return 0;
}