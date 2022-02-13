#include <iostream>

using namespace std;

bool visited[1000];
pair<int, int> doors[1000];
bool cmp(pair<int, int> a, pair<int, int> b){
    return a.first < b.first;
}
int main(void){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> doors[i].first;//number of cows lining up at door[i]
        doors[i].second = i;//door number
    }
    sort(door, doors+n, cmp);
    int room[n];
    int ans = 0;
    for(int i = 0; i < n; i++){
        int cowsput = 0;
        int idx = doors[i].second;
        int steps = 0;
        while(cowsput < doors[i].first){
            if(!visited[idx]){
                visited[idx] = true;
                cowsput++;
            }
            cowsput = cowsput+1 % n;
        }

    }


    return 0;
}