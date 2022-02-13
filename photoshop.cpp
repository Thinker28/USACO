#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

#define ll long long
int main(void){
    ifstream cin("photo.in");
    ofstream cout("photo.out");
    ll n;
    cin >> n;
    ll arr[n - 1];
    for(ll i = 0; i < n - 1; i++){
        cin >> arr[i];
    }
    ll arr2[n];
    ll visited[n];
    fill(visited, visited + n, 0);
    for(int i = 1; i <= 1000; i++){
        int past = i;
        arr2[0] = i;
        for(int j = 0; j < n - 1; j++){
            arr2[j + 1] = arr[j] - past;
            past = arr2[j + 1];
        }
        bool works = true;
        for(int j = 0; j < n; j++){
            visited[arr2[j]]++;
        }
        for(int j = 0; j < n; j++){
            if(visited[j] > 1){
                works = false;
                break;
            }
        }
        if(works){
            for(int j = 0; j < n; j++){
                if(j == n - 1){
                    cout << arr2[j] << "\n";
                }else{
                    cout << arr2[j] << " ";
                }
                
            }
            return 0;
        }else{
            fill(visited, visited + n, 0);  
        }
    }
    

    return 0;
}