#include <iostream>
#include <vector>
using namespace std;

int main(void){
    int a, b, n;
    cin >> a >> b >> n;
    int minCost = 1e9;
    vector<vector<int> > paths;
    vector<int> pathcost;
    for(int i = 0; i < 2 * n; i++){
        int cost, length;
        cin >> cost >> length;
        vector<int> path;
        bool found = false;
        bool update = false;
        int pos1;
        for(int j = 0; j < length; j++){
            int a1;
            cin >> a1;
            path.push_back(a1);
            if(a1 == a){
                found = true;
                pos1 = j;
            }else if(a1 == b && found){
                minCost = min(minCost, cost);
                update = true;
            } 
        }
        if(!found){
            paths.push_back(path);
            pathcost.push_back(cost);
        }else if(!update && found){
            for(int j = pos1; j < length; j++){
                bool thereIs = false;
                for(int k = 0; k < paths.size(); k++){
                    int pos2;
                    for(int v: paths[k]){
                        if(v == path[j]){
                            thereIs = true;
                            pos2 = j;
                            break;
                        }
                    }
                    if(thereIs){
                        for(int v = pos2; v < paths[k].size(); v++){
                            if(paths[k][v] == b){
                                minCost = min(minCost, pathcost[k]);
                            }
                        }
                    }
                }
            }
        }
    }
    cout << minCost << "\n";
    return 0;
}