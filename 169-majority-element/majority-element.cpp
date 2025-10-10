class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int f = 1;
        int result = nums[0];
        for(int i=1;i<n;i++){
            if(f==0){
                f = 1;
                result = nums[i];
            }
            else{
                if(result == nums[i]){
                    f++;
                }
                else{
                    f--;
                }
            }
        }
        return result;
    }
};