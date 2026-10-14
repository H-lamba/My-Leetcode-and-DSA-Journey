class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";
        for(int i = 9; i>=1; i--)
        {
            if(i == 0) break;
            int count = sum/i;
            for(int j = 0; j<count; j++)
            ans+=to_string(i);
            sum = sum- (count*i);
        }
        if(ans.size()>num) return "";
        else if(ans.size()<num) 
        {
            int n = num- ans.size();
            while(n>0)
            {
                n--;
                ans+=to_string(0);
            }
        }
        return ans;
    }
};