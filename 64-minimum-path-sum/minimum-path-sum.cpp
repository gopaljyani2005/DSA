int funct(vector<vector<int>> & grid, int i, int j, int m, int n, vector<vector<int>> & dp){
    if(i==m-1 && j==n-1){
        return grid[i][j];
    }
    else if(i>=m || j>=n){
        return INT_MAX;
    }
    else if(dp[i][j] != INT_MAX){
        return dp[i][j];
    }
    else{
        int right = funct(grid, i, j+1, m, n, dp);
        int down = funct(grid, i+1, j, m, n, dp);
        dp[i][j] = grid[i][j] + min(right, down);
        return dp[i][j];
    }
}

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n,INT_MAX));

        return funct(grid, 0, 0, m, n, dp);
    }
};