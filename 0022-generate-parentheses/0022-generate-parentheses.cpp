class Solution {
public:
    void fun(int n, vector<string> & ans, string s, int opencount, int closecount)
    {
        if(s.size()==2*n)
        {
            ans.push_back(s);
            return ;
        }

        if(opencount<n)
        {
            fun(n, ans, s+'(', opencount+1, closecount);
        }
        if(closecount<opencount)
        {
           
            fun(n, ans, s+')', opencount, closecount+1);
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        fun(n, ans, "", 0, 0);
        return ans;
    }
};