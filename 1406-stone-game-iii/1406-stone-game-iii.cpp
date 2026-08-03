class Solution {
public:
    int fun(int index, vector<int> & arr, vector<int> & dp)
    {
        if(index>=arr.size()) return 0;
        if(dp[index]!=INT_MIN) return dp[index];
        int curr = -1e9;
        int tempsum = 0;
        for(int i = 0; i<3; i++)
        {
            int newid = index+i;
            if(newid<arr.size())
            {
                tempsum+= arr[newid];
                curr  = max(curr,tempsum - fun(newid+1, arr, dp));
            }
        }
        return dp[index] = curr;
    }
    string stoneGameIII(vector<int>& arr) {
        vector<int> dp(arr.size(),INT_MIN);
        int ans = fun(0, arr, dp);
        if(ans>0) return "Alice";
        else if(ans == 0) return "Tie";
        else return "Bob";
    }
};