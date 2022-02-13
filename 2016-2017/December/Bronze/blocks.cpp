#include <iostream>
#include <fstream>
using namespace std;

int arr[26];
int side1[26], side2[26];

int main(void){
    ifstream fin("blocks.in");
    ofstream fout("blocks.out");
    int n;
    string word1, word2;
    
    fin >> n;
    for(int i = 0; i < n; i++){
        fin >> word1 >> word2;
       
        for(int j = 0; j < word1.length(); j++){
            side1[word1[j] - 'a']++;
        }
        
        for(int j = 0; j < word2.length(); j++){
            side2[word2[j] - 'a']++;
        }
        
        for(int j = 0; j < 26; j++){
            arr[j] += max(side1[j], side2[j]);
            side1[j] = side2[j] = 0;
        }
    }
    
    for(int i = 0; i < 26; i++){
        fout << arr[i] << "\n";
    }

    return 0;
}
