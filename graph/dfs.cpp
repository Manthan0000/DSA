#include<bits/stdc++.h>
using namespace std;

void DFS(int node, vector<vector<int>> &graph, vector<bool> &visited)
{
    visited[node] = true;
    cout << node << " ";

    for (int neighbour : graph[node])
    {
        if (!visited[neighbour])
        {
            DFS(neighbour, graph, visited);
        }
    }
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

    vector<bool> visited(n, false);

    int startNode = 0;
    DFS(startNode, graph, visited);

    return 0;
}
