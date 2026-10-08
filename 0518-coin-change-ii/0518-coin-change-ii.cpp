class Solution {
public:
    int solve(int index, int amount, vector<int> & coins, vector<vector<int>> & dp)
    {
        if(index==0)
        {
            if(amount%coins[0]==0)
            return 1;
            return 0;
        }
        if(dp[index][amount]!=-1) return dp[index][amount];
        int pick = 0;
        if(amount>=coins[index])
        pick = solve(index, amount-coins[index], coins, dp);
        int notpick = solve(index-1, amount, coins, dp);
        return dp[index][amount]= pick+notpick;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, -1));
        return solve(coins.size()-1, amount, coins, dp);
    }
};