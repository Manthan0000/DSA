#include<bits/stdc++.h>
using namespace std;
bool detect(int src, vector<int> adj[], int vis[]){
    vis[src] = 1;
    queue<pair<int,int>> q;     
    q.push({src , -1});        
    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for(auto adjacentNode : adj[node]){
            if(!vis[adjacentNode])
            {
                vis[adjacentNode] = 1;
                q.push({adjacentNode , node});
            }
            else if(parent != adjacentNode)
            {
                return true;
            }
        }
    }
    return false;
}

bool isCycle(int V, vector<int> adj[]){
    int vis[V] = {0};
    for(int i = 0; i < V; i++)
    {
        if(!vis[i])
        {
            if(detect(i, adj, vis))
                return true;
        }
    }
    return false;
}

int main(){
    int V = 5;
    vector<int> adj[V];
    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0};
    adj[3] = {1, 4};
    adj[4] = {3};
    if(isCycle(V, adj))
        cout << "Cycle Present";
    else
        cout << "No Cycle";
    return 0;
}