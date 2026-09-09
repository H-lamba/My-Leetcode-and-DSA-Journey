class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();
        vector<vector<int>> dist(r, vector<int>(c, -1));
        queue<vector<int>> q;
        for(int i = 0; i<r; i++)
        {
            for(int j = 0; j<c; j++)
            {
                if(mat[i][j] == 0)
                {
                    dist[i][j] = 0;
                    q.push({i, j, 0});
                }
            }
        }
        vector<int> dx = {-1, 1, 0 ,0};
        vector<int> dy = {0,0,-1,1};
        while(!q.empty())
        {
            int x = q.front()[0];
            int y = q.front()[1];
            int sum = q.front()[2];
            q.pop();
            for(int i = 0; i<4; i++)
            {
                int nx = x+dx[i];
                int ny = y+dy[i];
                if (nx >= 0 && ny >= 0 && nx < r && ny < c && dist[nx][ny] == -1) {
                    dist[nx][ny] = sum + 1;
                    q.push({nx, ny, sum + 1});
                }
            }
        }
        return dist;
    }
};