class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        if(nums.back()<k) return k;
        int i = 0;
        while(nums[i]<k)
        {
            i++;
        }
        int temp = k;
        for(int j = i; j<nums.size(); j++)
        {
            if(nums[j]==temp)
            {
                temp+=k;
            }
        }
        return temp;
    }
};