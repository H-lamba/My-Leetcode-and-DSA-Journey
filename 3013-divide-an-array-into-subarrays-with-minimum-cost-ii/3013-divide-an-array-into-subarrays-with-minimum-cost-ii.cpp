class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        long long ans = nums[0];
        long long temp = 1e18;
        long long current_sum = 0;
        multiset<int> lo, hi;
        int n = nums.size();
        for(int i = 1; i<n; i++)
        {
            if(lo.empty() || nums[i]<*lo.rbegin())
            {
                lo.insert(nums[i]);
                current_sum+= nums[i];
            }
            else
            {
                hi.insert(nums[i]);
            }
            if(i>dist+1)
            {
                int last = nums[i-dist-1];
                if(last<=*lo.rbegin())
                {
                    lo.erase(lo.find(last));
                    current_sum-=last;
                }else{
                    hi.erase(hi.find(last));
                }
            }
           while(lo.size() < k - 1 && !hi.empty())
            {
                int val = *hi.begin();
                lo.insert(val);
                current_sum += val;
                hi.erase(hi.begin());
            }
            while(lo.size()>k-1)
            {
                int val = *lo.rbegin();
                hi.insert(val);
                current_sum -= val;
                lo.erase(prev(lo.end()));
            }

            if(i>=dist+1)
            {
                temp = min(temp, current_sum);
            }
        }
        return ans+temp;
    }
};