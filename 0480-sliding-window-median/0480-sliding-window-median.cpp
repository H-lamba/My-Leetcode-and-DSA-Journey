class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> lo, hi;
        vector<double> ans;
        int n = nums.size();
        for(int i = 0; i<n; i++)
        {
            if(lo.empty()|| nums[i]<= *lo.rbegin())
            {
                lo.insert(nums[i]);
            }
            else
            {
                hi.insert(nums[i]);
            }
            if(i>=k)
            {
                int last = nums[i-k];
                if(last<=*lo.rbegin())
                {
                    lo.erase(lo.find(last));
                }
                else
                {
                    hi.erase(hi.find(last));
                }
            }

            while(lo.size()>hi.size()+1)
            {
                hi.insert(*lo.rbegin());
                lo.erase(prev(lo.end()));
            }
            while(lo.size()<hi.size())
            {
                lo.insert(*hi.begin());
                hi.erase(hi.begin());
            }
            if(i>=k-1)
            {
                if(k%2!=0)
                {
                    ans.push_back((double)*lo.rbegin());
                }
                else
                {
                    ans.push_back(((double)*lo.rbegin()+(double)*hi.begin())/2.0);
                }
            }
        }
        return ans;
    }
};