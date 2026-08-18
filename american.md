# Amex Sample Question 
**Description:**
You are given a 3×3 integer matrix grid representing a grid of cells. Each cell contains a certain number of stones, represented by grid[i][j]. The total number of stones across the entire grid is guaranteed to be exactly 9.

In one move, you can transfer one stone from its current cell to any directly adjacent cell (up, down, left, or right).

Return the minimum number of moves required to place exactly one stone in every cell of the grid.

Input:
A 2D array grid of size 3×3.
Output:
An integer representing the minimum total moves.
Constraints:
grid.length == 3
grid[i].length == 3
0≤grid[i][j]≤9
The sum of all elements in grid is exactly 9.

## Solution

```bash
#include <iostream>
using namespace std;
#include <vector>

int performdp(vector<vector<int>> & arr, vector<pair<int, int>>& non, vector<pair<int, int>>& z,vector<bool> & visited, int index)
{
    if(index>=non.size()) return 0;

    int ans = 0;
    int temp_step = INT_MAX;
    if(arr[non[index].first][non[index].second]>1)
    {
        for(int j = 0; j<z.size(); j++)
        {
            if(visited[j])
            {
                visited[j] = false;
                arr[non[index].first][non[index].second]--;
                int curr = abs(non[index].first- z[j].first)+ abs(non[index].second - z[j].second);
                temp_step = min(temp_step,curr+performdp(arr, non, z, visited, index));
                arr[non[index].first][non[index].second]++;
                visited[j] = true;
            }
        }
    }
    else{
        temp_step = min(temp_step, performdp(arr, non, z, visited, index+1));
    }
    return temp_step;
}
int fun(vector<vector<int>> & arr)
{
    vector<pair<int, int>> non;
    vector<pair<int, int>> z;
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<3; j++)
        {
            if(arr[i][j]>1)
            non.push_back({i,j});
            if(arr[i][j]==0)
            {
                z.push_back({i,j});
            }
        }
    }
    vector<bool> visited(z.size(), true);
   int ans = performdp(arr, non, z, visited, 0);
   return ans;
}
int main()
{
    vector<vector<int>> v(3, vector<int>(3,0));
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<3; j++)
        {
            int x;
            cin>>x;
            v[i][j] = x;
        }
    }
    int ans = fun(v);
    cout<<ans;
    return 0;
}

```
 
