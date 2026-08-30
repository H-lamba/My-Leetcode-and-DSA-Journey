class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini = 0;
        int n = nums.size();
        int maxi = 0;
        for(int i = 1; i<n; i++)
        {
            if(nums[i]>nums[maxi])
            {
                maxi = i;
            }
            if(nums[i]<nums[mini])
            {
                mini = i;
            }
        }
        int cost1 = max(mini, maxi)+1;
        int cost2 = n- min(mini, maxi);
        int cost3 = min(mini, maxi)+1+n-max(mini, maxi);
        int cost4 = n - min(mini, maxi)+max(mini, maxi)+1;
        return min(min(cost1, cost2), min(cost3, cost4));
    }
};