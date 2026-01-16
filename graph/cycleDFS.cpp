#include<bits/stdc++.h>
using namespace std;

bool dfs(int node, int parent, vector<int> adj[], int vis[])
{
    vis[node] = 1;
    for(auto adjacentNode : adj[node])
    {
        if(!vis[adjacentNode])
        {
            if(dfs(adjacentNode, node, adj, vis))
                return true;
        }
        else if(adjacentNode != parent)
        {
            return true;  
        }
    }
    return false;
}

bool isCycle(int V, vector<int> adj[])
{
    int vis[V] = {0};
    for(int i = 0; i < V; i++)
    {
        if(!vis[i])
        {
            if(dfs(i, -1, adj, vis))
                return true;
        }
    }
    return false;
}

int main()
{
    int V = 5;
    vector<int> adj[V];
    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0, 3};
    adj[3] = {1, 2, 4};
    adj[4] = {3};
    if(isCycle(V, adj))
        cout << "Cycle Present";
    else
        cout << "No Cycle";
    return 0;
}