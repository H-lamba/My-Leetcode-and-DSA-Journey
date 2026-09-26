class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        for(auto i : knowledge)
        {
            mp[i[0]] = i[1];
        }
        string ans = "";
        for(int i = 0 ; i<s.size(); i++)
        {
            if(s[i] == '(')
            {
                i++;
                string query = "";
                while(s[i]!=')')
                {
                    query+=s[i];
                    i++;
                }
                if(mp.find(query)==mp.end())
                {
                    ans+='?';
                }
                else
                {
                    ans+=mp[query];
                }
            }
            else
            ans+=s[i];
        }
        return ans;
    }
};