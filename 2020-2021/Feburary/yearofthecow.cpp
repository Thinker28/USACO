// // #include <iostream>

// // using namespace std;

// // const int MAXN = 105;
// //     // int years[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
// //     // // 1 is Ox, 2 Tiger, 3 Rabbit, 4 Dragon, 5 Snake, 6 Horse, 7 Goat, 8 Monkey, 9 Rooster, 10 Dog, 11 Pig, 12 Rat

// //     string name[MAXN];
// //     string born[MAXN];
// //     string in;
// //     string indication[MAXN];
// //     string kindYear[MAXN];
// //     string year[MAXN];
// //     string from;
// //     string name2[MAXN];

// // int main(void){
// //     int n;
// //     cin >> n;
// //     for(int i = 0; i < n; i++){
// //         cin >> name[i] >> born[i] >> in >> indication[i] >> kindYear[i] >> year[i] >> from >> name2[i];
// //     }

// //     int years_apart = 0;
// //     int a, preva;
// //     for(int i = 0; i < n; i++){
// //         string prevname = name[i];
// //         if(i != 0 && kindYear[i - 1] == "Ox") preva = 1;
// //         else if(i != 0 && kindYear[i - 1] == "Tiger") preva = 2;
// //         else if(i != 0 && kindYear[i - 1] == "Rabbit") preva = 3;
// //         else if(i != 0 && kindYear[i - 1] == "Dragon") preva = 4;
// //         else if(i != 0 && kindYear[i - 1] == "Snake") preva = 5;
// //         else if(i != 0 && kindYear[i - 1] == "Horse") preva = 6;
// //         else if(i != 0 && kindYear[i - 1] == "Goat") preva = 7;
// //         else if(i != 0 && kindYear[i - 1] == "Monkey") preva = 8;
// //         else if(i != 0 && kindYear[i - 1] == "Rooster") preva = 9;
// //         else if(i != 0 && kindYear[i - 1] == "Dog") preva = 10;
// //         else if(i != 0 && kindYear[i - 1] == "Pig") preva = 11;
// //         else{
// //             a = 12;
// //         }

// //         if(kindYear[i] == "Ox") a = 1;
// //         else if(kindYear[i] == "Tiger") a = 2;
// //         else if(kindYear[i] == "Rabbit") a = 3;
// //         else if(kindYear[i] == "Dragon") a = 4;
// //         else if(kindYear[i] == "Snake") a = 5;
// //         else if(kindYear[i] == "Horse") a = 6;
// //         else if(kindYear[i] == "Goat") a = 7;
// //         else if(kindYear[i] == "Monkey") a = 8;
// //         else if(kindYear[i] == "Rooster") a = 9;
// //         else if(kindYear[i] == "Dog") a = 10;
// //         else if(kindYear[i] == "Pig") a = 11;
// //         else{a = 12;}

// //         if(name[i] == "Elsie"){
// //             cout << abs(years_apart) << "\n";
// //         }else if((i == 0) || name2[i] == prevname){
// //             if(indication[i] == "previous"){
// //               if(i == 0){
// //                 years_apart -= 12 + (a - 1);
// //               }else{
// //                 years_apart -= 12 + abs(preva - a);
// //               }
// //             // years_apart -= 12 + abs(preva - a);   //(12 + a) + 1;
// //             }else{
// //             years_apart += a;
// //           }
// //         }


// //     }


// // }
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main(void){
  int ans = 0;
  int n;
  cin >> n;
  string names[12] = {"Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"};
  unordered_map<string, unordered_set<string> > um;
  um["Bessie"].insert("Ox");
  unordered_map<string, unordered_set<string> >:: iterator it;
  for(int i = 0; i < n; i++){
    string name1, indication, type, name2, trash;
    cin >> name1 >> trash >> trash >> indication >> type >> name2;
    int pos1, pos2; 
    if(i == 0){
      um[name1].insert(indication);
      for(int j = 0; j < 12; j++){
        if(names[j] == indication){
          pos1 = j;
        }
      }
      if(indication == "After"){
        ans += pos1;
      }else if(indication == "Before"){
        ans += 12 - pos1;
      }
    }
    if(i != 0){
      it = um.find(name2);
    }
    for(int j = 0; j < 12; j++){
      string a = it->second;
      if(names[j] == um[it->second]){
        pos2 = j;
      }else if(names[j] == type){
        pos1 = j;
      }
    }
    if(indication == "Before" && pos1 < pos2){
      ans -= pos2 - pos1;
    }else if(indication == "Before" && pos1 > pos2){
      ans -= (12 - pos1) + pos2;
    }else if(indication == "After" && pos1 > pos2){
      ans += pos1 - pos2;
    }else if(indication == "After" && pos1 < pos2){
      ans += (12 - pos2) + pos1;
    }
  }
  cout << ans << "\n";
  return 0;
}