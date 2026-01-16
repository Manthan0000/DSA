#include<bits/stdc++.h>
using namespace std;
void BFS(int start, vector<vector<int>> &graph)
{
    int n = graph.size();             
    vector<bool> visited(n, false);    
    queue<int> q;                    

    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int node = q.front();       
        q.pop();                    
        cout << node << " ";         

        for(auto next : graph[node]){
            if (!visited[next]){
                visited[next] = true;
                q.push(next);
            }
        }
    }
    cout << endl;
}

int main()
{
    int n = 6;
    vector<vector<int>> graph(n);
    graph[0] = {1, 2};
    graph[1] = {0, 3};
    graph[2] = {0, 4};
    graph[3] = {1, 5};
    graph[4] = {2};
    graph[5] = {3};

    int startNode = 0;
    BFS(startNode, graph);
    return 0;
}
