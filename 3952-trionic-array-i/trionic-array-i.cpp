class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int size = nums.size();
        if(size == 3){
            return false;
        }
        
        int i = 1;
        while(i<size && nums[i]>nums[i-1]){
            i++;
        }
        int p = i-1;
        i = size-2;
        while(i>=0 && nums[i]<nums[i+1]){
            i--;
        }
        int q = i+1;

        if(p>=q ||p==0 || q==size-1){
            return false;
        }
        else{
            for(int i=p+1;i<=q;i++){
                if(nums[i]<nums[i-1]){
                    continue;
                }
                else{
                    return false;
                }
            }
            return true;
        }
    }
};