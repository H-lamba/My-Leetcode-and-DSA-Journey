class Solution {
public:
    void fun(vector<int> & nums, vector<vector<int>> & ans, vector<int> & temp, vector<bool> & visit)
    {
        if(temp.size()==nums.size())
        ans.push_back(temp);
        
        for(int i = 0; i<nums.size(); i++)
        {
            if(visit[i])
            {
                temp.push_back(nums[i]);
                visit[i] = false;
                fun(nums, ans, temp, visit);
                temp.pop_back();
                visit[i] = true;
            }
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        for(int i = 0; i<nums.size(); i++)
        {
            vector<bool> visit(nums.size(), true);
            temp.push_back(nums[i]);
            visit[i] = false;
            fun(nums, ans, temp, visit);
            temp.pop_back();
        }
        return ans;
    }
};