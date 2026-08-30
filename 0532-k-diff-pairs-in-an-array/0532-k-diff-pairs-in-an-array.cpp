class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int count = 0;
        int n = nums.size();
        set<pair<int, int>> s;
        for(int i = 0; i<n; i++)
        {
            for(int j = i; j<n; j++)
            {
                if(i==j)
                continue;
                if(abs(nums[i]-nums[j]) == k)
                {
                    int a = min(nums[i], nums[j]);
                    int b = max(nums[i], nums[j]);
                    s.insert({a, b});
                }
            }
        }
        return s.size();
    }
};