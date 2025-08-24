class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int size = nums.size();
        int ans = 0;
        vector<int> perfix(size, 0);
        vector<int> suffix(size, 0);
        int sum;

// calculate perfix sum of the given array and store;
        sum = 0;
        for(int i=0;i<size;i++){
            sum+=nums[i];
            if(nums[i] == 0){
                perfix[i] = sum;
                sum = 0;
            }
        }
        ans = sum;

// calculate suffix sum of array and store it ;
        sum = 0;
        for(int i=size-1;i>=0;i--){
            sum+=nums[i];
            if(nums[i] == 0){
                suffix[i] = sum;
                sum = 0;
            }
        }

// write logic here for update answer according to the given condition ;
        ans = max(ans,suffix[0]);
        for(int i=0;i<size-1;i++){
            if(nums[i] == 0){
                ans = max(ans, perfix[i] + suffix[i]);
            }
        }

        // one element should delete 
        if(ans == size){
            return ans-1;
        }

        // return the answer here ;
        return ans;
    }
};