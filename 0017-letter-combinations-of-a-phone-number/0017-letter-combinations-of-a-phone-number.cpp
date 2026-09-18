class Solution {
public:
    void fun(string & digits, vector<string> & v, vector<string> & ans, int index, string s)
    {
        if(index==digits.size())
        {
            ans.push_back(s);
            return;
        }
        int number = digits[index]-'0';
        string chars = v[number];
        for(char i : chars)
        {
            fun(digits, v, ans, index+1, s+i);
        }
        return ;
    }
    vector<string> letterCombinations(string digits) {
        vector<string> v = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        fun(digits, v, ans, 0, "");
        return ans;
    }
};