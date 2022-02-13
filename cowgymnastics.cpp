// #include <iostream>
// #include <fstream>
// // #include <assert.h>
// using namespace std;

// int main(void){
//     ifstream fin("gymnastics.in");
//     ofstream fout("gymnastics.out");
//      int k, n;
//      fin >> k >> n;
//      int nums[k][n];
//      for(int i = 0; i < k; i++){
//          for(int j = 0; j < n; j++){
//              fin >> nums[i][j];
//          }
//      }

//     int positions[n][n];
//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < n; j++){
//             positions[i][j] = 0;
//         }
//     }
//     for(int i = 0; i < k; i++){
//         for(int ref = 0; ref < n; ref++){
//             for(int scan = ref + 1; scan < n; scan++){
//                 // assert(nums[i][ref] - 1 < n);
//                 // assert(nums[i][ref] >= 0);
//                 // assert(nums[i][scan] < n);
//                 // assert(nums[i][scan] >= 0);
//                 positions[nums[i][ref] - 1][nums[i][scan] - 1]++;
//             }   
//         }
//     }
    
//     int counter = 0;
//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < n; j++){
//             if(positions[i][j] == k){
//                 counter++;
//             }
//         }
//     }
//     fout << counter << "\n";

//     return 0;
// }
#include <iostream>
#include <fstream>

using namespace std;

int main(void){
    ifstream fin("gymnastics.in");
    ofstream fout("gymnastics.out");
     int k, n;
     fin >> k >> n;
     int nums[k][n];
     for(int i = 0; i < k; i++){
         for(int j = 0; j < n; j++){
             fin >> nums[i][j];
         }
     }

    int positions[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            positions[i][j] = 0;
        }
    }
    for(int i = 0; i < k; i++){
        for(int ref = 0; ref < n; ref++){
            for(int scan = ref + 1; scan < n; scan++){
                positions[nums[i][ref] - 1][nums[i][scan] - 1]++;
            }   
        }
    }
    
    int counter = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(positions[i][j] == k){
                counter++;
            }
        }
    }
    fout << counter << "\n";

    return 0;
}