#include <fstream>

using namespace std;

bool cant[105][105];

int main(void){
    ifstream cin("revegetate.in");
    ofstream cout("revegetate.out");
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        cant[a - 1][b - 1] = cant[b - 1][a - 1] = true;
    }
    int output[n];
    for(int i = 0; i < n; i++){
        bool pasture_types[4] = {true, true, true, true};
        for(int j = 0; j < i; j++){
            if(cant[i][j]){
                pasture_types[output[j]] = false;
            }
        }

        for (int j = 0; j < 4; j++) {
            if (pasture_types[j]) {
                output[i] = j;
                break;
            }
        }
        cout << output[i] + 1;
    }

    return 0;
}