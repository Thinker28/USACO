// #include <iostream>
// #include <algorithm>
// #include <fstream>
//
//
// using namespace std;
//
// int main(void){
//   ifstream fin("teleport.in");
//   ofstream fout("teleport.out");
//   int a, b, x, y;
//   fin >> a >> b >> x >> y;
//   int minD = abs(b - a);
//   int distance;
//   if(abs(a - x) + abs(b - y) < minD || abs(a - y) + abs(b - x) < minD) {
//     if(abs(a - x) + abs(b - y) < abs(a - y) + abs(b - x)){
//       distance = abs(a - x) + abs(b - y);
//     }else if(abs(a - y) + abs(b - x) < abs(a - x) + abs(b - y)) {
//       distance = abs(a - y) + abs(b - x);
//     }else{
//       distance = abs(b - a);
//     }
//     /*if(abs(a - x) < abs(a - y)){
//       distance = abs(a - x) + abs(b - y);
//     }else{
//       distance = abs(a - y) + abs(b - x);
//     }*/
//
//   }
//   minD = distance;
//
//   fout << minD << "\n";
//
//   return 0;
// }
//
// //3 10 8 2
// // minD = 7
// // if(abs(3 - 8) < minD || abs(3 - 2) < minD)
// #include <iostream>
// #include <algorithm>
// #include <fstream>


// using namespace std;

// int main(void){
//   ifstream fin("teleport.in");
//   ofstream fout("teleport.out");
//   int a, b, x, y;
//   fin >> a >> b >> x >> y;

//   int minD = min(abs(b - a), min(abs(a - y) + abs(b - x), abs(a - x) + abs(b - y)));

//   fout << minD << "\n";
//   return 0;
// }