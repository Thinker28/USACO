#include <iostream>
#include <vector>

using namespace std;

struct Edge{
    int a, b, w;
}
int main(void){
    int n, m;
    cin >> n >> m;   
    vector<Edge> edges;
    for(int i = 0; i < m; i++){
        Edge push;
        cin >> push.a >> push.b >> push.w;
        edges.push_back(push);
    }
    vector<int> distance(n+1);
    for(int i = 1; i <= n; i++){
        distance[i] = 1e9;
    }
    distance[1] = 0;  
    for(int i = 1; i < n; i++){
        for(auto e: edges){
            distance[e.b] = max(distance[e.b], distance[e.a]+e.w); 
        }
    }  
    return 0;

}