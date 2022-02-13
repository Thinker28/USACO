#include <iostream>
#include <fstream>
using namespace std;

int main(void){
    ifstream cin("promote.in");
    ofstream cout("promote.out");
    pair<int, int> p[4];
    for(int i = 0; i < 4; i++){
        cin >> p[i].first >> p[i].second;
    }
    int platG = p[3].second - p[3].first;
    int goldG = p[2].second - p[2].first + platG;
    int silverG = (p[1].second - p[1].first) + goldG;
    cout << silverG << "\n" << goldG << "\n" << platG << "\n";
    return 0;
}