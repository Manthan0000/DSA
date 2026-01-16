#include<bits/stdc++.h>
using namespace std;

vector<int> shortestPath(int N, vector<vector<int>> &edges, int src){
    vector<int> adj[N];
    for(auto it : edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    vector<int> dist(N, 1e9);
    dist[src] = 0;
    queue<int> q;
    q.push(src);

    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it : adj[node]){
            if(dist[node] + 1 < dist[it]){
                dist[it] = dist[node] + 1;
                q.push(it);
            }
        }
    }
    vector<int> ans(N, -1);
    for(int i = 0; i < N; i++){
        if(dist[i] != 1e9){
            ans[i] = dist[i];
        }
    }
    return ans;
}

int main(){
    int N = 6;
    vector<vector<int>> edges = {
        {0,1},
        {0,2},
        {1,3},
        {2,3},
        {3,4},
        {4,5}
    };
    int src = 0;
    vector<int> ans = shortestPath(N, edges, src);
    for(int x : ans){
        cout << x << " ";
    }
    return 0;
}
