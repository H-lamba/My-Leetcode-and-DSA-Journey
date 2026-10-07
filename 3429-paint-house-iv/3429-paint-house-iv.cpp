class Solution {
public:
    long long fun(int index, vector<vector<int>> & cost, int top, int btm, vector<vector<vector<long long>>> & dp)
    {
        if(index==cost.size()/2) return 0;
        if(dp[index][top+1][btm+1]!= -1) return dp[index][top+1][btm+1];
        //filling the top
        long long ans = 1e14;
        for(int i = 0 ; i<3; i++)
        {
            if(i == top)continue;
            else
            {
                for(int j = 0; j<3; j++)
                {
                    if(j == btm || j == i) continue;
                    else
                    {
                        ans = min(ans, cost[index][i]+cost[cost.size()-index-1][j]+fun(index+1, cost, i, j,dp));
                    }
                }
            }
        }
        return dp[index][top+1][btm+1] = ans;
    }
    long long minCost(int n, vector<vector<int>>& cost) {
        vector<vector<vector<long long>>> dp(n/2, vector<vector<long long>>(4, vector<long long>(4, -1)));
        return fun(0, cost,  -1, -1, dp);
    }  
};