#include <iostream>
#include <fstream>
using namespace std;

int main(void){
    // ifstream cin("bcounting.in");
    // ofstream cout("bcounting.out");
    int n, q;
    cin >> n >> q;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    pair<int, pair<int, int> > prefix[n];
    prefix[n - 1] = make_pair(0, make_pair(0, 0));
    for(int i = 0; i < n; i++){
        if(arr[i] == 1){
            prefix[n - 1].first++;
        }else if(arr[i] == 2){
            prefix[n - 1].second.first++;
        }else if(arr[i] == 3){
            prefix[n - 1].second.second++;
        }
    }
    pair<int, pair<int, int> > past = prefix[n - 1];
    for(int i = n - 2; i >= 0; i--){
        if(arr[i] == 1){
            prefix[i] = past;
            prefix[i].first--;
        }else if(arr[i] == 2){
            prefix[i] = past;
            prefix[i].second.first--;
        }else if(arr[i] == 3){
            prefix[i] = past;
            prefix[i].second.second--;
        }        

    }
    // for(int i = 0; i < n; i++){
    //     cout << prefix[i].first << " " << prefix[i].second.first << " " << prefix[i].second.first << "\n";
    // }
    for(int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;
        cout << prefix[b].first - prefix[a].first << " " << prefix[b].second.first - prefix[a].second.first << " " << prefix[b].second.second - prefix[a].second.second << "\n";
    }
    return 0;
}