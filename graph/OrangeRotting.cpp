#include<bits/stdc++.h>
using namespace std;
int orangesRotting(vector<vector<int>> &grid)
{
    int rows = grid.size();
    int cols = grid[0].size();
    queue<pair<pair<int,int>, int>> q; 

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            if(grid[i][j] == 2)
            {
                q.push({{i, j}, 0});
            }
        }
    }

    int maxtime = 0;
    int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}}; 

    while(!q.empty())
    {
        auto current = q.front();
        q.pop();

        int x = current.first.first;
        int y = current.first.second;
        int time = current.second;

        maxtime = max(maxtime, time);
        for(auto d : dir)
        {
            int nx = x + d[0];
            int ny = y + d[1];
            if(nx >= 0 && ny >= 0 &&
                nx < rows && ny < cols &&
                grid[nx][ny] == 1)
            {
                grid[nx][ny] = 2;             
                q.push({{nx, ny}, time + 1}); 
            }
        }
    }

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            if(grid[i][j] == 1)
            {
                return -1; 
            }
        }
    }
    return maxtime;
}

int main()
{
    vector<vector<int>> grid = {
        {2,1,1},
        {1,1,0},
        {0,1,1}
    };
    cout << orangesRotting(grid);
    return 0;
}
