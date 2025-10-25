int funct(string &word1, string &word2, int i, int j, vector<vector<int>> & dp){
    if(i<0){
        return j+1;
    }
    else if(j<0){
        return i+1;
    }
    else if(dp[i][j]!=INT_MAX){
        return dp[i][j];
    }
    else if(word1[i]==word2[j]){
        return funct(word1, word2, i-1, j-1, dp);
    }
    else{
        int ins = funct(word1, word2, i, j-1, dp);
        int del = funct(word1, word2, i-1, j, dp);
        int rep = funct(word1, word2, i-1, j-1, dp);
        dp[i][j] = 1+min(ins, min(del, rep));
        return dp[i][j];
    }
}

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector<int>> dp(n1, vector<int> (n2, INT_MAX));
        return funct(word1, word2, n1-1, n2-1, dp);
    }
};