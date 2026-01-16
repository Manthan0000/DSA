#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], int vis[], stack<int> &st){
    vis[node] = 1;
    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(it, adj, vis, st);
        }
    }
    st.push(node);
}

vector<int> topoSort(int V, vector<int> adj[]){
    int vis[V] = {0};
    stack<int> st;
    for(int i = 0; i < V; i++){
        if(!vis[i]){
            dfs(i, adj, vis, st);
        }
    }
    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
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