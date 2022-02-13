#include <iostream>
#include <fstream>
#include <vector>
#include <queue>


using namespace std;

int main(void){
    ifstream cin("cowdance.in");
    ofstream cout("cowdance.out");
    int n, tmax;
    cin >> n >> tmax;
    vector<int> t(n);
    for(int i = 0; i < n; i++){
        cin >> t[i];
    }
    int low = 1;
    int high = n;
    while(low <= high){
        int mid = (low + high) / 2;
        priority_queue<int> pq; 
        int size = 0;
        int j = 0;
        int time = 0;
        while(size < mid && j < n){
            pq.push(-t[j]);
            size++;
            j++;
        }
        while((int)pq.size()){
            time += max(0, -pq.top() - time);
            pq.pop();
            if(j < n){
                pq.push(-(t[j]+time));
                j++;
            }  
        }
        if(time > tmax){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    cout << high + 1 << "\n";
    return 0;   
}