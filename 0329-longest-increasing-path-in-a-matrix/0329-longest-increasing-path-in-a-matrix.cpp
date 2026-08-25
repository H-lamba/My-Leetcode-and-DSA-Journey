class Solution {
private:
    // Direction arrays for moving up, down, left, right
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    int n, m;

    int dfs(int x, int y, vector<vector<int>>& matrix, vector<vector<int>>& memo) {
        // 1. Base case / DP Check: If already calculated, return the cached answer
        if (memo[x][y] > 0) {
            return memo[x][y];
        }
        
        int max_path = 1; // The cell itself counts as a path of length 1
        
        // 2. Explore all 4 valid neighbors
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            // 3. Ensure within bounds AND strictly increasing
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && matrix[nx][ny] > matrix[x][y]) {
                // Recursively find the max path from the neighbor and add 1 for the current cell
                max_path = max(max_path, 1 + dfs(nx, ny, matrix, memo));
            }
        }
        
        // 4. Save the result in the DP memoization table and return it
        return memo[x][y] = max_path;
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        
        n = matrix.size();
        m = matrix[0].size();
        
        // DP table initialized to 0
        vector<vector<int>> memo(n, vector<int>(m, 0)); 
        int longest_path = 0;
        
        // 5. Try starting a path from every cell in the matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                longest_path = max(longest_path, dfs(i, j, matrix, memo));
            }
        }
        
        return longest_path;
    }
};