// #include <fstream>

// using namespace std;

// const int MAXN = 1005;

// int r[MAXN];

// int main(void){
//     ifstream fin("cbarn.in");
//     ofstream fout("cbarn.out");
//     int n;
//     fin >> n;
//     for(int i = 0; i < n; i++){
//         fin >> r[i];
//     }
    
//     int sum = 0;
//     int perfect_sum = 0;
//     for(int i = 0; i < n; i++){
//          sum += r[i];
//          perfect_sum += r[i] * i;
//     }
    
//     int min_totalD = perfect_sum;
//     for (int i = 1; i < n; i++) {
//         perfect_sum = perfect_sum - (sum - r[i - 1]) + r[i - 1] * (n - 1);
//         min_totalD = min(min_totalD, perfect_sum);
//     }
    
//     fout << min_totalD << "\n";
//     return 0;
// }

#include <iostream> 
#include <fstream>
using namespace std;

int main(void){
    ifstream cin("cbarn.in");
    ofstream cout("cbarn.out");
    int n;
    cin >> n;
    int barns[n];
    for(int i = 0; i < n; i++){
        cin >> barns[i];
    }
    int minCount = 1e9;
    for(int i = 0; i < n; i++){
        bool visited[n];
        fill(visited, visited + n, false);
        int total = 0;
        int count = 0;
        int j = i;
        while(true){
            if(visited[j]){
                break;
            }
            visited[j] = true;
            total += barns[j] * count; 
            count++;
            j = (j + 1) % n;
        }
        minCount = min(total, minCount);
    }
    cout << minCount << "\n";
    return 0;
}