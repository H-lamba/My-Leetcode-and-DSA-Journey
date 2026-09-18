class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n = mat.size();
        int m = mat[0].size();
        int row = n-1;
        int col = 0;
        while(row>=0 && col<=m-1)
        {
            if(mat[row][col] == target) return true;
            if(mat[row][col]>target)
            row--;
            else 
            col++;
        }
        return false;
    }
};