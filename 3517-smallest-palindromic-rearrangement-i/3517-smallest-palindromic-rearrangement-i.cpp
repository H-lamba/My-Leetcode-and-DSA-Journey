class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> v1(26,0);
        for(char i : s)
        {
            v1[i-'a']++;
        }
        char z = ' ';
        string ans = "";
        for(int i = 0 ; i<26; i++)
        {if(v1[i]%2==0)
            {
                int x = v1[i]/2;
                char t = 'a'+i;
                for(int j = 0; j<x; j++)
                {
                    ans+=t;
                }
            }else
            {
                z = 'a'+i;
                int x = v1[i]/2;
                char t = 'a'+i;
                for(int j = 0; j<x; j++)
                {
                    ans+=t;
                }
            }
        }
        if(z!=' ')
        {
            ans+=z;
            for(int i = ans.size()-2; i>=0; i--)
            ans+= ans[i];
        }
        else
        {
            for(int i = ans.size()-1; i>=0; i--)
            ans+= ans[i];
        }
        return ans;
    }
};