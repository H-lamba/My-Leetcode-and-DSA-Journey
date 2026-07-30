class Solution {
public:
    int fun(vector<int> & nums, int t, int index, vector<int> & dp)
    {
        if(index == nums.size()-1) return 0;
        if(index >=nums.size()) return -1;
        if(dp[index]!=-2) return dp[index];

        int ans = -1;
        for(int j = index+1; j<nums.size(); j++)
        {
            if(abs(nums[index]-nums[j])<=t)
            ans = max(ans, 1+fun(nums, t, j, dp));
        }
        if(ans == 0) ans = -1;
        return dp[index] = ans;
    }
    int maximumJumps(vector<int>& nums, int t) {
        vector<int> dp(nums.size()+1, -2);
        return fun(nums,t,0, dp);
    }
};