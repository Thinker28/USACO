// #include <iostream>
// #include <fstream>
// using namespace std;

// char aout[100][100];
// int main(void){
//   ifstream fin("cowsignal.in");
//   ofstream fout("cowsignal.out");
//     int m, n, k;

//     fin >> m;
//     fin >> n;
//     fin >> k;

//     // cout << "output\n";
//     for (int row = 0; row < m; row++){
//         for (int col = 0; col < n; col++){
//             char c;
//             fin >> c;
//             //cout << c;

//             for (int i = 0; i < k; i++){
//                 for (int j = 0; j < k; j++){
//                   aout[k*row+i][k*col+j] = c;

//                 }
//             }
//         }
//         //cout << "\n";
//     }

//     for (int i=0; i < k * m; i++) {
//         for (int j=0; j < k * n; j++) {
//             fout << aout[i][j];
//         }
//       fout << "\n";
//     }
// }
#include <iostream>
#include <fstream>
using namespace std;

int main(void){
  ifstream cin("cowsignal.in");
  ofstream cout("cowsignal.out");
  int m, n, k;
  cin >> m >> n >> k;
  for(int i = 0; i < m; ++i){
    string s;
    cin >> s;
    string s2;
    for(int j = 0; j < n; j++){
      for(int k2 = 0; k2 < k; k2++){
        s2 += s[j];
      }
    }
    for(int j = 0; j < k; j++){
      cout << s2 << "\n";
    }
  }
  return 0;
}