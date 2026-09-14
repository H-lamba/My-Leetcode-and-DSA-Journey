class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i<m; i++)
        {
            if(grid[0][i] == 1)
            {
                q.push({0,i});
                grid[0][i] = 0;
            }
            if(grid[n-1][i] == 1)
            {
                q.push({n-1,i});
                grid[n-1][i] = 0;
            }
        }
        for(int i = 0; i<n; i++)
        {
            if(grid[i][0] == 1)
            {
                q.push({i,0});
                grid[i][0] = 0;
            }
            if(grid[i][m-1] == 1)
            {
                q.push({i,m-1});
                grid[i][m-1] = 0;
            }
        }
        int dx [] = {-1,1,0,0};
        int dy [] = {0,0,-1,1};
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i = 0; i<4; i++)
            {
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny] == 1)
                {
                    q.push({nx, ny});
                    grid[nx][ny] = 0;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<m; j++)
            {
                ans+= grid[i][j];
            }
        }
        return ans;
    }
};