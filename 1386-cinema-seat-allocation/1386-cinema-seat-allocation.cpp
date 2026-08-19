class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& r) {
       unordered_map<int,vector<int>> mp;
       for(int i = 0; i<r.size(); i++)
       {
        int a = r[i][0];
        int b = r[i][1];
        mp[a].push_back(b);
       }
       
       int ans = 2*n - mp.size()*2;
       
       for(auto i: mp)
       {
        bool w1 = true;
        bool w2 = true;
        bool w3 = true;
        
        for(int j : i.second)
        {
            if(j==2 || j==3 || j==4 || j==5 ) w1 = false;
            if(j==4 || j==5 || j==6 || j==7) w2 = false;
            if(j==6 || j==7 || j==8 || j==9) w3 = false;
        }
        
        if(w1 && w3) {
            ans+=2;
        }
        else if(w1||w2||w3) {
            ans+=1;
        }
       }
       return ans;
    }
};