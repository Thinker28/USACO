#include <iostream>


int Fac(int x){
  if(x==1){
    return 1;
  }else{
    return x*Fac(x-1);
  }
}

using namespace std;

int main(void){
  char a;
  do{
    cin >> a;
  }
  while(a != '!');
  cout << Fac(a) << "\n";


  cout << Fac(a);



}
