#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<pair<int,int>> adj[], int S){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> dist(V, 1e9);
    dist[S] = 0;
    pq.push({0, S});

    while(!pq.empty()){
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(auto it : adj[node]){
            int adjNode = it.first;
            int edgeWeight = it.second;
            if(dis + edgeWeight < dist[adjNode]){
                dist[adjNode] = dis + edgeWeight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}

int main(){
    int V = 5;
    vector<pair<int,int>> adj[V];
    
    adj[0] = {{1,2}, {2,4}};
    adj[1] = {{2,1}, {3,7}};
    adj[2] = {{4,3}};
    adj[3] = {{4,1}};
    adj[4] = {};
    int S = 0;
    vector<int> ans = dijkstra(V, adj, S);
    for(int x : ans){
        cout << x << " ";
    }
    return 0;
}