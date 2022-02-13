#include <iostream>
#include <vector>
using namespace std;

vector<int> dice1(4);
vector<int> dice2(4);
vector<int> dice3(4);

// bool nontransistive(int test){
// 	vector<int> t(3);
// 	for(int i = 0; i < 4; i++){
// 		for(int j = 0; j < 4; j++){
// 			t[1 + (dice1[i] > dice2[j]) - (dice2[j] > dice1[i])] += 1;
// 		}
// 	}
// 	int win2 = t[0];
// 	int win1 = t[2];
// 	int cnt1 = (win1 > win2) - (win2 > win1);
// 	t[0] = t[1] = t[2] = 0;
// 	for(int i = 0; i < 4; i++){
// 		for(int j = 0; j < 4; j++){
// 			t[1 + (dice2[i] > dice3[j]) - (dice3[j] > dice2[i])] += 1;
// 		}
// 	}
// 	win2 = t[0];
// 	win1 = t[2];
// 	int cnt2 = (win1 > win2) - (win2 > win1);
// 	t[0] = t[1] = t[2] = 0;
// 	for(int i = 0; i < 4; i++){
// 		for(int j = 0; j < 4; j++){
// 			t[1 + (dice3[i] > dice1[j]) - (dice1[j] > dice3[i])] += 1;
// 		}
// 	}
// 	win2 = t[0];
// 	win1 = t[2];
// 	int cnt3 = (win1 > win2) - (win2 > win1);
// 	if(cnt1 == 1 && cnt2 == 1 && cnt3 == 1){
// 		return true;
// 	}else{
// 		return false;
// 	}
// }
bool nontransistive(){
	int xw, yw;
	int xw2, yw2;
	int xw3, yw3;
	xw = yw = xw2 = yw2 = xw3 = yw3 = 0;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			if(dice1[i] > dice2[j]){
				xw++;
			}else if(dice1[i] < dice2[j]){
				yw++;
			}
		}
	}
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			if(dice2[i] > dice3[j]){
				xw2++;
			}else if(dice2[i] < dice3[j]){
				yw2++;
			}
		}
	}
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			if(dice3[i] > dice1[j]){
				xw3++;
			}else if(dice3[i] < dice1[j]){
				yw3++;
			}
		}
	}
	if(xw > yw && xw2 > yw2 && xw3 > yw3){
		return true;
	}
	return false;
}
int main(void){
	int t;
	cin >> t;
	for(int test = 0; test < t; test++){
		for(int i = 0; i < 4; i++){
			cin >> dice1[i];
		}
		for(int i = 0; i < 4; i++){
			cin >> dice2[i];
		}
		bool good = false;
		for(int face1 = 1; face1 <= 10; face1++){
			for(int face2 = 1; face2 <= 10; face2++){
				for(int face3 = 1; face3 <= 10; face3++){
					for(int face4 = 1; face4 <= 10; face4++){
						dice3[0] = face1;
						dice3[1] = face2;
						dice3[2] = face3;
						dice3[3] = face4;
						if(nontransistive()){
							// cout << "\n" << face1 << " " << face2 << " " << face3 << " " << face4 << "\n";
							good = true;
							break;
						}
					}
					if(good){
						break;
					}

				}
				if(good){
					break;
				}

			}
			if(good){
				break;
			}

		}
		if(good){
			cout << "yes\n";
		}else{
			cout << "no\n";
		}

	}
	return 0;
}