#include <iostream>
#include <vector>
using namespace std;

int main(void){
    int t;
    cin >> t;
    char ans[400][400][400];
    int size[t];
    for(int testcase = 0; testcase < t; testcase++){
        vector<pair<int, int> > pos(2);
        int n;
        cin >> n;
        char arr[n][n];
        size[testcase] = n;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> arr[i][j];
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(arr[i][j] == '*'){
                    pos.push_back(make_pair(i, j));
                }
            }
        }
        arr[pos[0].first][pos[1].second] = '.';
        arr[pos[0].second][pos[1].first] = '.';
        pos.clear();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                ans[testcase][i][j] = arr[i][j];
            }
        }
    }
    for(int i = 0; i < t; i++){
        for(int j = 0; j < size[i]; j++){
            for(int k = 0; k < size[i]; k++){
                cout << ans[i][j][k] << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}