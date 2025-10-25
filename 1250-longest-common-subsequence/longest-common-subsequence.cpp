int funct(string & text1, string & text2, int index1, int index2, vector<vector<int>> & dp){
    if(index1<0 || index2<0){
        return 0;
    }
    else if(dp[index1][index2]!=-1){
        return dp[index1][index2];
    }
    else if(text1[index1] == text2[index2]){
        return 1 + funct(text1, text2, index1-1, index2-1, dp);
    }
    else{
        int caseone = funct(text1, text2, index1-1, index2, dp);
        int casetwo = funct(text1, text2, index1, index2-1, dp);
        int casethree = funct(text1, text2, index1-1, index2-1, dp);
        dp[index1][index2] =  max(caseone, max(casetwo, casethree));
        return dp[index1][index2];
    }
}

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>> dp(n1, vector<int>(n2, -1));
        return funct(text1, text2, n1-1, n2-1, dp);
    }
};