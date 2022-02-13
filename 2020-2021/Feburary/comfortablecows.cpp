//  #include <iostream>

//  using namespace std;

// int dx[4] = {1, -1, 0, 0};
// int dy[4] = {0, 0, 1, -1};
// bool occupy[1005][1005];

// int main(void){
//     int n;
//     cin >> n;
//     int X[n];
//     int Y[n];

//     int numComforable = 0;
//     for(int i = 0 ; i < n; i++){
//         cin >> X[i] >> Y[i];
//         occupy[X[i]][Y[i]] = true;
        
//         int numAdjacent = 0;
//         for (int dir = 0; dir < 4; dir++) {
//             int x2 = X[i] + dx[dir];
//             int y2 = Y[i] + dy[dir];

//             if (x2 <= 1000 && y2 <= 1000 && 
//                 x2 >= 0 && y2 >= 0 && 
//                 occupy[x2][y2]) {
//                 numAdjacent++;
//                 int numAdjacent2 = 0;
//                 for (int dir = 0; dir < 4; dir++) {
//                     int x3 = x2 + dx[dir];
//                     int y3 = y2 + dy[dir];
//                     if (x3 <= 1000 && y3 <= 1000 && 
//                         x3 >= 0 && y3 >= 0 && 
//                         occupy[x3][y3]) {
//                         numAdjacent2++;
//                     }
//                 }
//                 if (numAdjacent2 == 3) {
//                     numComforable++;
//                 } else if (numAdjacent2 == 4) {
//                     numComforable--;
//                 }
//             }
//         }
        
//         if (numAdjacent == 3) {
//             numComforable++;
//         }
        
//         cout << numComforable << "\n";
//     }
     
//     return 0;
// }
// #include <iostream>

// using namespace std;

// int dx[4] = {1, -1, 0, 0};
// int dy[4] = {0, 0, 1, -1};
// bool occupy[1005][1005];
// int main(void){
//     int n;
//     cin >> n;
//     int comf = 0;
//     for(int i = 0; i < n; i++){
//         int x, y;
//         cin >> x >> y;
//         int nComf2 = 0;
//         for(int j = 0; j < 4; j++){
//             int nComf = 0;
//             if(x + dx[j] <= 1000 && x + dx[j] >= 0 && y + dy[j] <= 1000 && y + dy[j] >= 0 && occupy[x + dx[j]][y + dy[j]]){
//                 nComf2++;
//                 for(int k = 0; k < 4; k++){
//                     if(x + dx[j] + dx[k] <= 1000 && x+dx[j] + dx[k] >= 0 && y+dy[j] + dy[k] <= 1000 && y+dy[j] + dy[k] >= 0 && occupy[x+dx[j]+dx[k]][y+dy[j]+dy[k]]){
//                         nComf++;
//                     }
//                 }
//             }
//             if(nComf == 3){
//                 comf--;
//             }
//         }
//         if(nComf2 == 4){
//             comf--;
//         }
//         for(int j = 0; j < 4; j++){
//             int nComf = 0;
//             if(x + dx[j] < 1000 && x + dx[j] >= 0 && y + dy[j] < 1000 && y + dy[j] >= 0 && occupy[x+dx[j]][y+dy[j]]){
//                 for(int k = 0; k < 4; k++){
//                     if(x+dx[j] + dx[k] < 1000 && x + dx[j] + dx[k] >= 0 && y + dy[j] + dy[k] < 1000 && y+dy[j] + dy[k] >= 0 && occupy[x+dx[j]+dx[k]][y+dy[j]+dy[k]]){
//                         nComf++;
//                     }
//                 }
//             }
//             if(nComf == 2){
//                 comf++;
//             }
//         }
//         occupy[x][y] = true;
//         cout << comf << "\n";
//     }
//     return 0;
// }