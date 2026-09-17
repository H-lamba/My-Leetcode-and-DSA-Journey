class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        for(int i = 0; i<n; i++)
        {
            bool re = true;
            for(int j = 0; j<n; j++)
            {
                if(i == j)
                continue;
                if(s[i]==s[j])
                {
                    re = false;
                    break;
                }
            }
            if(re) return i;
        }
        return -1;
    }
};