// #include <iostream>
// #include <algorithm>
// #include <fstream>

// using namespace std;

// const int MAXN = 1005;

// int n;
// int balls[MAXN];
// // fwdEdge[i] means edge from i to i + 1
// bool fwdEdge[MAXN];
// // bckEdge[i] means edge from i to i - 1
// bool bckEdge[MAXN];

// int main(){
//   ifstream fin("hoofball.in");
//   ofstream fout("hoofball.out");
//     fin >> n;
//     for (int i = 0; i < n; i++) {
//         fin >> balls[i];
//     }
    
//     sort(balls, balls + n);
    
//     for (int i = 0; i < n; i++) {
//         if (i == 0) {
//             fwdEdge[i] = true;
//         } else if (i == n - 1) {
//             bckEdge[i] = true;
//         } else if(balls[i] - balls[i - 1] <= balls[i + 1] - balls[i]) {
//             bckEdge[i] = true;
//         } else {
//             fwdEdge[i] = true;
//         }
//     }
    
//     int numGroups = 0;
//     for (int i = 0; i < n; ) {
//         int lenFwd = 0;
//         int lenBck = 0;
//         for (int j = i; j < n && fwdEdge[j]; j++) {
//             lenFwd++;
//         }
        
//         for (int j = i; j < n && (j == n - 1 || bckEdge[j + 1]); j++) {
//             lenBck++;
//         }
        
//         i += max(lenFwd, lenBck) + 1;
//         numGroups++;
//     }
    
//     fout << numGroups << "\n";
//     return 0;
// }
