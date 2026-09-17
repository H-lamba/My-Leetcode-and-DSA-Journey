class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int p = 1;
        int count = 0;
        int index = -1;
        for(int i = 0; i<nums.size(); i++ )
        {
            if(nums[i] == 0)
            {
                count++;
                index = i;
            }
            p = p*nums[i];
        }   
        vector<int> ans(nums.size(), 0);
        if(count>1) return ans;
        if(count == 1)
        {
            int p1 = 1;
            for(int i = 0; i<nums.size(); i++)
            {
                if(i == index) continue;
                p1 *= nums[i];
                //cout<<p1<<endl;
            }
            //cout<<p1<<endl;
            ans[index] = p1;
            return ans;
        }
        else
        {
            for(int i = 0; i<nums.size(); i++)
            {
                ans[i] = p/nums[i];
            }
        }
        return ans;
    }
};