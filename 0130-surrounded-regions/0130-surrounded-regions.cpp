class Solution {
public:
    void solve(vector<vector<char>>& board) {
        queue<vector<int>> q;
        int n = board.size();
        int m = board[0].size();
        vector<vector<char>> ans(n, vector<char>(m, 'X'));
        for(int i = 0; i<m; i++)
        {
            if(board[0][i]=='O')
            {
                q.push({0,i});
                ans[0][i] = 'O';
                board[0][i]= 'X';
            }
            if(board[n-1][i]=='O')
            {
                q.push({n-1, i});
                ans[n-1][i] = 'O';
                board[n-1][i] = 'X';
            }
        }
        for(int i = 0; i<n; i++)
        {
            if(board[i][0]=='O')
            {
                q.push({i,0});
                ans[i][0] = 'O';
                board[i][0]= 'X';
            }
            if(board[i][m-1]=='O')
            {
                q.push({i, m-1});
                ans[i][m-1] = 'O';
                board[i][m-1] = 'X';
            }
        }
        vector<int> dx = {0,0,-1,1};
        vector<int> dy = {-1,1,0,0};
        while(!q.empty())
        {
            int x = q.front()[0];
            int y = q.front()[1];
            q.pop();
            for(int i = 0; i<4; i++)
            {
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx>=0 && ny>=0 && nx<n && ny<m && board[nx][ny] == 'O')
                {
                    board[nx][ny] = 'X';
                    ans[nx][ny] = 'O';
                    q.push({nx, ny});
                }
            }
        }
        board = ans;
        return;
    }
};