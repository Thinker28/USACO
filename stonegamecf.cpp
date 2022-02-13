// #include <iostream>
// #include <vector>
// using namespace std;

// int main(void){
//     int t;
//     cin >> t;
//     vector<int> vec;
//     for(int i = 0; i < t; i++){
//         int n;
//         cin >> n;
//         for(int j = 0; j < n; j++){
//             int b;
//             cin >> b;
//             vec.push_back(b);
//         }
//         int max = -1;
//         long long min = 900000000;
//         for(int j = 0; j < n; j++){
//             if(vec.at(j) > max){
//                 max = vec.at(j);

//             }
//             if(vec.at(j) < min){
//                 min = vec.at(j);
//             }
//         }
//         int counter = 0;
//         int right = n - 1;
//         int left = 0;
//             while(true){
//                 if(vec.at(left) != max || vec.at(right) != min){
//                 counter++;
//                 left++;
//             }else if(vec.at(right) != max || vec.at(right) != min){
//                 counter++;
//                 // vec.erase(vec.begin() + right);
//                 right--;
//             }else{
//                 cout << counter << "\n";
//                 break;
//             }
//          }
//         vec.erase(vec.begin(), vec.end());

//     }
//     return 0;
// }
// //stereo hearts, and follow you

#include <iostream>
#include <vector>

using namespace std;

int main(void){
    int t;
    cin >> t;
    vector<int> vec;
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        for(int j = 0; j < n; j++){
            int a;
            cin >> a;
            vec.push_back(a);
        }
        long long min = 900000000;
        int max = -1;
        int minIdx, maxIdx;
        for(int j = 0; j < n; j++){
            if(vec.at(j) < min){
                min = vec.at(j);
                minIdx = j;
            }
            if(vec.at(j) > max){
                max = vec.at(j);
                maxIdx = j;
            }
        }
        int left = 0;
        int counter = 0;
        int right = n - 1;
        bool achieve1 = false;
        bool achieve2 = false;
        while(true){
            if(left != minIdx || left != maxIdx){
                left++;
                counter++;
            }else if(!achieve1 && left == minIdx || left == maxIdx){
                achieve1 = true;
                counter++;
            }
            if(right != minIdx || left != maxIdx){
                right--;
                counter++;
                
            }else if(!achieve2 && right == minIdx || right == maxIdx){
                achieve2 = true;
                counter++;
            }
            if(achieve1 && achieve2){
                cout << counter << "\n"; 
                break;
            }
            
        
        }
        vec.erase(vec.begin(), vec.end());
    }
    return 0;
}