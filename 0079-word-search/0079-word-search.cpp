class Solution {
public:
    bool search(vector<vector<char>> & board, string & word , int i, int j, string target)
    {
        target+=board[i][j];
        for(int k = 0; k<target.size(); k++)
        {
            if(target[k]!= word[k]) return false;
        }
        if(target.size()== word.size()) return true;
        bool ans = false;
        char c = board[i][j];
        board[i][j] = '.';
        int dx [] = {0,0,1,-1};
        int dy[] = {1,-1, 0 ,0};
        for(int k = 0; k<4; k++)
        {
            int ni = i +dx[k];
            int nj = j+dy[k];
            if(ni>=0 && nj>=0 && ni<board.size() && nj< board[0].size() && board[ni][nj]!='.')
            {
                ans = search(board,word, ni, nj,target);
                if(ans) return ans;
            }
        }
        board[i][j] = c;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        bool ans = false;
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<m; j++)
            {
                if(board[i][j] == word[0])
                {
                    if(search(board, word, i, j, "")) return true;
                }
            }
        }
        return false;
    }
};