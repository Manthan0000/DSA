#include<bits/stdc++.h>
using namespace std;

vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S){
    vector<int> dist(V, 1e8);
    dist[S] = 0;
    for(int i = 0; i < V-1; i++){
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
                dist[v] = dist[u] + wt;
            }
        }
    }
    for(auto it : edges){
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
            return {-1}; 
        }
    }
    return dist;
}

int main(){
    int V = 5;
    vector<vector<int>> edges = {
        {0,1,-1},
        {0,2,4},
        {1,2,3},
        {1,3,2},
        {1,4,2},
        {3,2,5},
        {3,1,1},
        {4,3,-3}
    };
    int S = 0;
    vector<int> ans = bellman_ford(V, edges, S);
    for(int x : ans){
        cout << x << " ";
    }
    return 0;
}