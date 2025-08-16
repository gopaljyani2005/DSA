int mod = pow(10,9) + 7;

int funct(int n, int x, int size, int i,vector<vector<int>> &dp){
    if(i==size){
        if(n==0){
            return 1;
        }
        else{
            return 0;
        }
    }
    else if(n==0){
        return 1;
    }
    else if(n<0){
        return 0;
    }
    else if(dp[i][n]!=-1){
        return dp[i][n];
    }
    
    int take = funct(n-pow(i,x),x,size,i+1, dp);
    int nottake = funct(n,x,size,i+1, dp);
    dp[i][n] =  (take + nottake)%mod;
    return dp[i][n];
}

class Solution {
public:
    int numberOfWays(int n, int x) {
        int size = 1;
        while(pow(size,x)<=n){
            size++;    
        }
        vector<vector<int>> dp(size+1,vector<int> (n+1,-1));

        return funct(n,x,size,1,dp);
    }
};

