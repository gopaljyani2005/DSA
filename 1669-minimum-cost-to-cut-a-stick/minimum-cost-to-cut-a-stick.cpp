int funct(int s, int e, vector<int> & cuts, vector<vector<int>> & dp){
    if(s == e){
        return 0;
    }
    else if(dp[s][e]!=-1){
        return dp[s][e];
    }
    else{
        int mini = INT_MAX;
        for(int i=s;i<e;i++){
            int ans = funct(s, i, cuts, dp) + funct(i+1, e, cuts, dp);
            mini = min(mini, ans);
        }
        dp[s][e] =  cuts[e]-cuts[s-1] + mini;
        return dp[s][e];
    }
}

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int size = cuts.size();
        sort(cuts.begin(),cuts.end());
        vector<int> temp;
        temp.push_back(0);
        for(int i=0;i<size;i++){
            temp.push_back(cuts[i]);
        }
        temp.push_back(n);

        vector<vector<int>> dp(size+2,vector<int>(size+2,-1));

        return funct(1,size+1,temp, dp);
    }
};