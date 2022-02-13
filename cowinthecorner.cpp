#include <iostream>
#include <cmath>
#include <set> 
#include <algorithm>
using namespace std;

int heron(int a, int b, int c){
    return (a+b+c)*(a+b-c)*(a-b+c)*(b+c-a);
}
int main(void){
    int n, l;
    cin >> n >> l;
    multiset<int> nums;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        nums.insert(a);
    }
    int maxarea = -1;
    pair<int, pair<int, int> > maxside;
    maxside.first = -1;
    maxside.second.first = -1;
    maxside.second.second = -1;
    for(int side1 = 0; side1 <= 200; side1++){
        for(int side2 = side1; side2 <= 200; side2++){
            for(int side3 = side2; side3 <= 400; side3++){
                if(side1 == 10 && side2 == 10 && side3 == 10){
                    if(side1 + side2 >= side3 && side1 == side2 && nums.count(side1) > 1 && side3 <= l){
                        cout << "hi\n";
                    }
                }
                if(side1 + side2 >= side3 && side1 == side2 && nums.count(side1) > 1 && side3 <= l){
                    if(heron(side1, side2, side3) > maxarea){
                        maxarea = heron(side1, side2, side3);
                        maxside.first = side1;
                        maxside.second.first = side2;
                        maxside.second.second = side3;
                    }
                }
                if(side1+side2 >= side3 && side1 != side2 && nums.count(side1) > 0 && nums.count(side2) > 0 && side3 <= l){
                    if(heron(side1, side2, side3) > maxarea){
                        maxarea = heron(side1, side2, side3);
                        maxside.first = side1;
                        maxside.second.first = side2;
                        maxside.second.second = side3;
                    }
                }
            }
        }
    }
    int arr[3];
    arr[0] = maxside.first;
    arr[1] = maxside.second.first;
    arr[2] = maxside.second.second;
    sort(arr, arr+3);
    cout << arr[0] << arr[1] << arr[2] << "\n";
    
    	
    // 6 1
    // 5 5 10 /10 10 19
    return 0;
}   