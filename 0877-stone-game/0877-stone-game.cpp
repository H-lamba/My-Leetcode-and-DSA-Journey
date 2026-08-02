class Solution {
public:
    // bool fun(int start, int end, vector<int> & piles,int chance,int alice, int bob)
    // {
    //     if(start>end)
    //     {
    //         return alice>bob;
    //     }
    //     if(chance % 2==0)
    //     {
    //         return fun(start+1, end, piles, chance+1, alice+piles[start], bob) || fun(start, end-1,piles, chance+1, alice+piles[end], bob);
    //     }
    //     else
    //     {
    //         return fun(start+1, end, piles, chance+1, alice, bob+piles[start]) || fun(start, end-1,piles, chance+1, alice, bob+piles[end]);
    //     }
    // }
    int dp[501][501];
    int solve(vector<int>& nums,int left ,int right){
        if(left == right)return nums[left];
        if(dp[left][right] != -1){
            return dp[left][right];
        }
        int chooseleft = nums[left]-solve(nums,left+1,right);
        int chooseright = nums[right]-solve(nums,left,right-1);

        return dp[left][right]= max(chooseleft,chooseright);
    }
    bool stoneGame(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int diff = solve(nums,0,nums.size()-1);
        if(diff >= 0)return true;
        else
        return false;
    }
};