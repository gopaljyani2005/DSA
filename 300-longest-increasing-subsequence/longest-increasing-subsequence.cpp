class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n,1);

        int ptr = n-1;
        while(ptr>=0){
            int ele = nums[ptr];
            int f = 0;
            int index = ptr+1;
            while(index<n){
                if(ele<nums[index])
                    f = max(f, dp[index]);
                index++;
            }
            dp[ptr] = 1+f;
            ptr--;
        }

        int ans = 1;
        return *max_element(dp.begin(), dp.end());
    }
};