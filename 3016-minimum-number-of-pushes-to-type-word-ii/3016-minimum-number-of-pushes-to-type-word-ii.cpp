class Solution {
public:
    int minimumPushes(string s) {
        map<char, int> freq;
        for(char i :s)
        {
            freq[i]++;
        }
        vector<pair<char, int>> v(freq.begin(), freq.end());
        sort(v.begin(), v.end(), [](pair<char, int> a , pair<char, int> b){
            return a.second>b.second;
        });

        int ans = 0;
        for(int i = 0; i<v.size(); i++)
        {
            ans= ans+ (v[i].second)*(i/8+1);
        }
        return ans;
    }
};