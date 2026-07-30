class Solution {
public:
    int minimumPushes(string s) {
        int n = s.size();
        int ans = 0;
        vector<string> v(8, "");
        for(int i = 0; i<n; i++)
        {
            v[i%8]+=s[i];
            ans+=v[i%8].size();
        }
        return ans;
    }
};