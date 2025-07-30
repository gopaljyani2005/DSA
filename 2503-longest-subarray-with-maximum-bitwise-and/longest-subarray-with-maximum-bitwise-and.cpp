class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int size = nums.size();
        int ans = 1;
        int maxi = *max_element(nums.begin(),nums.end());
        int l = 0;
        int r = 0;
        while(r<size){
            if(nums[r]==maxi){
                l = r;
                while(r<size && nums[r]==maxi){
                    r++;
                }
                ans = max(ans,r-l);
            }
            else{
                r++;
            }
        }
        return ans;
    }
};