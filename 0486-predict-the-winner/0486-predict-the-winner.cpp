class Solution {
public:
    bool fun(int start, int end, vector<int> & nums, int chance, int p1, int p2)
    {
        if(end<start)
        {
            return p1>=p2;
        }
        if(chance == 0)
        {
            return fun(start+1, end, nums, chance+1, p1+nums[start], p2) || fun(start, end-1, nums, chance+1, p1+nums[end], p2);
        }
        else
        {
            return fun(start+1, end, nums, chance-1, p1, p2+nums[start]) && fun(start, end-1, nums, chance-1, p1, p2+nums[end]);   
        }
    }
    bool predictTheWinner(vector<int>& nums) {
        return fun(0, nums.size()-1, nums, 0, 0,0);
    }
};