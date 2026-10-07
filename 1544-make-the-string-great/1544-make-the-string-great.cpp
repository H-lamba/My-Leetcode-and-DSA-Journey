class Solution {
public:
    string makeGood(string s) {
       string ans = "";
       for(char c : s)
       {
        if(ans.size()==0) ans+=c;
        else
        {
            if(c == ans.back()) ans+= c;
            else if( toupper(c)==ans.back() || tolower(c)== ans.back()) ans.pop_back();
            else ans+=c;
        }
       }
       return ans;
    }
};