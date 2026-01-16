#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
public:
    vector<int> parent, size;
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i = 0; i <= n; i++){
            parent[i] = i;
        }
    }
    int findUPar(int node){
        if(node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v){
        int pu = findUPar(u);
        int pv = findUPar(v);
        if(pu == pv) return;
        if(size[pu] < size[pv]){
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else{
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

int kruskalMST(int V, vector<pair<int,pair<int,int>>> &edges){
    DisjointSet ds(V);
    sort(edges.begin(), edges.end());   // sort by weight
    int mstWt = 0;
    for(auto it : edges){
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;
        if(ds.findUPar(u) != ds.findUPar(v)){
            mstWt += wt;
            ds.unionBySize(u, v);
        }
    }
    return mstWt;
}

int main(){
    int V = 5;
    vector<pair<int,pair<int,int>>> edges;
    edges.push_back({5, {1, 2}});
    edges.push_back({2, {2, 5}});
    edges.push_back({5, {2, 3}});
    edges.push_back({7, {5, 1}});
    edges.push_back({2, {3, 4}});
    edges.push_back({1, {4, 5}});
    cout << kruskalMST(V, edges);
    return 0;
}