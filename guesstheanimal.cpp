#include <iostream>
#include <vector>
#include <fstream>


using namespace std;

vector<string> characteristics[105];
int num_common(int i, int j){
    int count = 0;
    for(int i2 = 0; i2 < characteristics[i].size(); i2++){
        string v = characteristics[i][i2];
        for(int j2 = 0; j2 < characteristics[j].size(); j2++){
            string d = characteristics[j][j2];
            if(v == d){
                count++;
            }
        }
    }
    return count;
}
int main(void){
    ifstream cin("guess.in");
    ofstream cout("guess.out");
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int num;
        string trash;
        cin >> trash >> num;
        for(int j = 0; j < num; j++){
            string char1;
            cin >> char1;
            characteristics[i].push_back(char1);
        }
    }
    int max1 = -1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j){
                continue;
            }else{
                max1 = max(max1, num_common(i, j));
            }
        }
    }
    cout << max1 + 1 << "\n";
    return 0;
}