#include <iostream>

using namespace std;

int main(void){
    int t;
    cin >> t;
    for(int t1 = 0; t1 < t; t1++){
        int a;
        cin >> a;
        //find the closest perfect square(lower_bound)
        int num = 0;
        while(true){
            if((num + 1) * (num + 1) > a){
                break;
            }
            num++;
        }
        int row = 0, col = num + 1;
        int number = num;
        while(true){
            if(number == a){
                break;
            }
            if(row > num + 1){
                col--;
            }else{
                row++;
            }
            number++;
        }
        cout << row << " " << col << "\n";

    }
    return 0;
}