#include<bits/stdc++.h>
using namespace std;

vector<int> topoSort(int V, vector<int> adj[]){
    int indegree[V] = {0};
    for(int i = 0; i < V; i++){
        for(auto it : adj[i]){
            indegree[it]++;
        }
    }
    
    queue<int> q;
    for(int i = 0; i < V; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    vector<int> topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for(auto it : adj[node]){
            indegree[it]--;
            if(indegree[it] == 0){
                q.push(it);
            }
        }
    }
    return topo;
}

int main(){
    int V = 6;
    vector<int> adj[V];
    adj[0] = {};
    adj[1] = {};
    adj[2] = {3};
    adj[3] = {1};
    adj[4] = {0, 1};
    adj[5] = {2, 0};
    vector<int> ans = topoSort(V, adj);
    for(int x : ans){
        cout << x << " ";
    }
    return 0;
}