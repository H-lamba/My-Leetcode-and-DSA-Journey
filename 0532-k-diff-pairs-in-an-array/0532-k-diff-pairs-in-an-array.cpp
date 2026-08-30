class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i = 0; i<nums.size(); i++)
        {
            if(i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int b = nums[i] + k;
            if(binary_search(nums.begin() + i + 1, nums.end(), b)) {
                ans++;
            }
        }
        return ans;
    }
};