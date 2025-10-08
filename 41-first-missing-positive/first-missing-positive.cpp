class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        for(int i=0;i<n;){
            if(nums[i]==i+1){
                i++;
                continue;
            }
            else if(nums[i]<=0){
                nums[i] = 0;
                i++;
            }
            else if(nums[i]>n){
                nums[i] = 0;
                i++;
                continue;
            }
            else{
                if(nums[i]==nums[nums[i]-1]){
                    i++;
                    continue;
                }
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        int ans = n+1;
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1){
                return i+1;
            }
        }
        return ans;
    }
};