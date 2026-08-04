class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int last = nums[0];
        vector<int> ans;
        for(int i = 1; i<nums.size(); i++)
        {
            int x = last + 1;

                while (x < nums[i]) {
                    ans.push_back(x);
                    x++;
                }

                last = nums[i];   
        }
        return ans;
    }
};