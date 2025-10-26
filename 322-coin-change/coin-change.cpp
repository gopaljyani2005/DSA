int funct(vector<int> & coins, int index, int amount, int &ans, int tempans, vector<vector<int>> & dp){
    if(amount<0){
        return INT_MAX;
    }
    else if(amount==0){
        return 0;
    }
    else if(index==coins.size()){
        return INT_MAX;
    }
    else if(dp[index][amount]!=-1){
        return dp[index][amount];
    }
    else{
        int take  = funct(coins, index, amount-coins[index], ans , tempans+1, dp);
        if(take!=INT_MAX){
            take++;
        }
        int nottake = funct(coins, index+1, amount, ans, tempans, dp);
        dp[index][amount] = min(take, nottake);
        return dp[index][amount];
    }
}

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1,-1));
        int ans = funct(coins, 0, amount, ans, 0, dp);
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};