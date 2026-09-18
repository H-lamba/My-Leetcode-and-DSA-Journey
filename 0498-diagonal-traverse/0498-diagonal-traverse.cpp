class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        unordered_map<int,vector<int>> mp;
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<m; j++)
            {
                mp[i+j].push_back(mat[i][j]);
            }
        }

        vector<int> ans;
        for(int i = 0; i<m+n-1; i++)
        {
            if(i%2!=0)
            {
                vector<int> temp = mp[i];
                for(int i : temp)
                ans.push_back(i);
            }
            else
            {
                vector<int> temp = mp[i];
                for(int j = temp.size()-1; j>=0; j--)
                {
                    ans.push_back(temp[j]);
                }
            }
        }
        return ans;
    }
};