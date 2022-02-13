#include <iostream>

using namespace std;

enum {
  JANUARY,
  FEBRUARY,
  MARCH,
  APRIL,
  MAY,
  JUNE,
  JULY,
  AUGUST,
  SEPTEMBER,
  OCTOBER,
  NOVEMBER,
  DECEMBER
};

int main(void){
  ifstream cin("friday.in");
  ifstream cout("friday.in");
  int n;
  cin >> n;
  int days[7];
  int day = 0;
  bool leapYear = false;
  int count = 2;

  for(int year = 1900; year < 1900 + n; year++){
    if((year % 400) == 0 || (year % 100 != 0 && year % 4 == 0)){
      leapYear = true;
    }
    
    for (int month = 0; month < 12; month++){
      if (month == SEPTEMBER || month == APRIL || month == JUNE || month == NOVEMBER){
        for(int day = 1; day <= 30; day++, count++){
          if(day == 13){
            days[count % 7]++;
          }
        }
      }
      
      else if(month == FEBRUARY && leapYear){
        for(int day = 1; day <= 29; day++, count++){
          if(day == 13){
            days[count % 7]++;
          }
        }
        leapYear = false;
      }
      
      else if(month == FEBRUARY && !leapYear){
        for(int day = 1; day <= 28; day++, count++){
          if(day == 13){
            days[count % 7]++;
          }
        }
      }
      
      else{
        for(int day = 1; day <= 31; day++, count++){
          if(day == 13){
            days[count % 7]++;
          }
        }
      }
    }

  }

  for(int i = 0; i < 7; i++){
    cout << days[i] << " ";
  }
  return 0;
}
//36 33 34 33 35 35 34