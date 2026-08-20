class Solution {
public:
    int fun(vector<vector<int>> & grid, vector<vector<int>> &zero , vector<vector<int>> &g1, string & mask, int index)
    {
        if(index>=g1.size())
        {
            return 0;
        }
        int a = g1[index][0];
        int b = g1[index][1];
        int ans = 1e9;
        if(grid[a][b]<=1)
        {
            ans = min(ans, fun(grid, zero, g1, mask, index+1));
        } 
        else
        {
            for(int i = 0; i<zero.size(); i++)
            {
                if(mask[i]=='1')
                {
                        mask[i]= '0';
                        grid[a][b]--;
                        ans = min(ans, (abs(a-zero[i][0])+abs(b-zero[i][1]))+fun(grid, zero, g1, mask, index));
                        grid[a][b]++;
                        mask[i] = '1';
                }
            }
        }
        return ans;
    }
    int minimumMoves(vector<vector<int>>& grid) {
        vector<vector<int>> zero;
        vector<vector<int>> g1;
        for(int i = 0; i<3; i++)
        {
            for(int j = 0 ; j<3; j++)
            {
                if(grid[i][j]==0)
                {
                    zero.push_back({i,j});
                }
                if(grid[i][j] >1)
                {
                    g1.push_back({i,j});
                }
            }
        }
        string mask = "";
        for(int i = 0 ; i<zero.size(); i++)
        {
            mask+='1';
        }
        return fun(grid, zero, g1, mask, 0);
    }
};