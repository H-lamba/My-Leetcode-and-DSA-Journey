class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int start = 0;
        int end = 0;
        int ans = 0;
        if(k==0 || nums.size()==0 ) return 0;
        while(end<nums.size())
        {
            freq[nums[end]]++;
            if(freq[nums[end]]>k)
            {
                while(freq[nums[end]]>k)
                {
                    freq[nums[start]]--;
                    ans = max(ans, end-start);
                    start++;
                }
            }
            end++;
        }
        ans = max(ans, end-start);
        return ans;
    }
};