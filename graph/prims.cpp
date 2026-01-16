#include<bits/stdc++.h>
using namespace std;

int prims(int V, vector<pair<int,int>> adj[]){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> vis(V, 0);
    pq.push({0, 0});
    int sum = 0;
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int wt = it.first;
        int node = it.second;
        
        if(vis[node] == 1) continue;
        vis[node] = 1;
        sum += wt;
        for(auto it : adj[node]){
            int adjNode = it.first;
            int edW = it.second;
            if(!vis[adjNode]){
                pq.push({edW, adjNode});
            }
        }
    }
    return sum;
}

int main(){
    int V = 5;
    vector<pair<int,int>> adj[V];
    adj[0] = {{1,2}, {3,6}};
    adj[1] = {{0,2}, {3,8}, {4,5}, {2,3}};
    adj[2] = {{1,3}, {4,7}};
    adj[3] = {{0,6}, {1,8}};
    adj[4] = {{1,5}, {2,7}};
    cout << prims(V, adj);
    return 0;
}