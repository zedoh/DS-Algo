#include <iostream>
#include <vector>
using namespace std ; 

/*
    *LeetCode problem <https://leetcode.com/problems/count-sub-islands/>
*/ 


// Moving in the grid
const int dr[4]{-1, 1, 0, 0}; // up , down , left , right
const int dc[4]{0, 0, -1, 1};
bool SubIsland;

bool valid(int r, int c, vector<vector<int>> &grid2)
{
    if (r >= grid2.size() || r < 0)
        return false;
    if (c >= grid2[0].size() || c < 0)
        return false;
    if (grid2[r][c] == 0)
        return false;
    return true;
}

int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
{
    int countisland{0};
    for (int i = 0; i < grid2.size(); ++i)
    {
        for (int j = 0; j < grid2[0].size(); ++j)
        {
            if (grid2[i][j])
            {
                SubIsland = 1;
                dfs(grid1, grid2, i, j);
                countisland += SubIsland;
            }
        }
    }
    return countisland;
}

void dfs(vector<vector<int>> &grid1, vector<vector<int>> &grid2, int r, int c)
{
    if (!valid(r, c, grid2))
        return;
    if (grid2[r][c] && !grid1[r][c])
    {
        SubIsland = 0;
        return;
    }
    grid2[r][c] = 0;

    for (int d = 0; d < 4; ++d)
    {
        dfs(grid1, grid2, r + dr[d], c + dc[d]);
    }
}