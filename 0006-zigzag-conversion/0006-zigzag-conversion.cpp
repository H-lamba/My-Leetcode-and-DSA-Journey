class Solution {
public:
    string convert(string s, int row) {
        if(row==1 || s.size()<=row) return s;
        int n = s.size();
        string ans = "";
        for(int i = 0; i<row; i++)
        {
            int diff_factor = 2*row-2*i-2;
            int jump = 2*i;
            int j = i;
            while(j<n)
            {
                if(diff_factor>0 && j<n)
                {
                    ans+=s[j];
                    j+=(diff_factor);
                }
                if(jump>0 && j<n)
                {
                    ans+=s[j];
                    j+= jump;
                }
            }
        }
        return ans;
    }
};