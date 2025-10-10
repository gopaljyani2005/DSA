int funct(int i , int j ,int m, int n, vector<vector<int>> & dp){
    if(i>=m || j>=n){
        return 0;
    }
    else if(i==m-1 && j==n-1){
        return 1;
    }
    else if(dp[i][j]!=-1){
        return dp[i][j];
    }
    else{
        dp[i][j] =  funct(i+1, j, m, n, dp) + funct(i,j+1, m, n, dp);
        return dp[i][j];
    }
}

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return funct(0,0,m,n, dp);
    }
};