#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

vector<int> graph[8];
vector<int> order;
vector<int> e;
bool first=true;
bool inorder[8]={0};
string cows[8]={"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};
int N;

void solve(int k){
    if(k==8){
        if(first) e=order;
        first=false;
        return;
    }
    if(k==0){
        for(int i=0; i<8; i++){
            order.push_back(i);
            inorder[i]=true;
            solve(k+1);
            order.pop_back();
            inorder[i]=false;
        }
    }else{
        for(int i:graph[order[k-1]]){
            if(inorder[i]) continue;
            order.push_back(i);
            inorder[i]=true;
            solve(k+1);
            order.pop_back();
            inorder[i]=false;
        }
    }

}

int main(){
    ifstream fin("lineup.in");
    ofstream fout("lineup.out");
    
    fin>>N;
    for(int i=0; i<N; i++){
        string c1, must, be, milked, beside, c2;
        fin>>c1>>must>>be>>milked>>beside>>c2;
        int cow1, cow2;
        for(int j=0; j<8; j++){
            if(cows[j]==c1) cow1=j;
            if(cows[j]==c2) cow2=j;
        }
        graph[cow1].push_back(cow2);
        graph[cow2].push_back(cow1);
    }
    for(int i=0; i<8; i++){
        if(graph[i].empty()){
            for(int j=0; j<8; j++){
                graph[j].push_back(i);
                graph[i].push_back(j);
            }
        }
        sort(graph[i].begin(), graph[i].end());
    }
    solve(0);
    for(int i:e) fout<<cows[i]<<endl;
}