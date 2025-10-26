long long mod = pow(10, 9) + 7;

int funct(vector<vector<int>> & grid, int i, int j, int m, int n, int k, vector<vector<vector<int>>> & dp){
    if(i==m-1 && j==n-1){
        dp[i][j][grid[i][j]%k] = 1;
        dp[i][j][k] = -1;
        return 0;
    }
    else if(dp[i][j][k]==-1){
        return 0;
    }
    else if(i==m-1){
        funct(grid, i, j+1, m, n,k, dp);
        for(int it = 0; it < k; it++){
            int index = ((grid[i][j])%k + it)%k;
            dp[i][j][index] =(dp[i][j][index]+dp[i][j+1][it])%mod;
        }
        dp[i][j][k] = -1;
        return 0;
    }
    else if(j==n-1){
        funct(grid, i+1, j, m, n,k, dp);
        for(int it = 0; it < k; it++){
            int index = ((grid[i][j])%k + it)%k;
            dp[i][j][index] =(dp[i][j][index]+dp[i+1][j][it])%mod;
        }
        dp[i][j][k] = -1;
        return 0;
    }
    else {
        funct(grid, i, j+1, m, n,k, dp);
        funct(grid, i+1, j, m, n,k, dp);
        for(int it = 0; it < k; it++){
            int index = ((grid[i][j])%k + it)%k;
            dp[i][j][index] =(dp[i][j][index]+dp[i][j+1][it])%mod;
        }
        for(int it = 0; it < k; it++){
            int index = ((grid[i][j])%k + it)%k;
            dp[i][j][index] =(dp[i][j][index]+dp[i+1][j][it])%mod;
        }
        dp[i][j][k] = -1;
        return 0;
    }
}

class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k+1, 0)));
        funct(grid, 0, 0, m, n, k, dp);
        return dp[0][0][0];

    }
};