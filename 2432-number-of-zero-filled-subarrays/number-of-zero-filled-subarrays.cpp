class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int size = nums.size();
        long long zero = 0;
        long long ans = 0;
        for(int i=0;i<size;i++){
            if(nums[i] == 0){
                zero++;
            }
            else{
                ans = ans + (zero*(zero+1)/2);
                zero = 0;
            }
        }
        ans = ans + (zero*(zero+1)/2);
        return ans;
    }
};