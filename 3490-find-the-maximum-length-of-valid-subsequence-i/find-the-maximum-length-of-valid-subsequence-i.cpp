class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int ans = 0;
        int x1 = 0,x2 = 0, x3 = 0;
        bool flag = true;
        if(nums[0]%2){
            flag = false;
        }
        int size = nums.size();
        for(int i=0;i<size;i++){
            if(nums[i]%2==0){
                x1++;
            }
            if(nums[i]%2!=0){
                x2++;
            }
            if(flag &&nums[i]%2==0){
                x3++;
                flag = false;
            }
            if(flag==false && nums[i]%2==1){
                x3++;
                flag = true;
            }
        }
        return max(x1,max(x2,x3));
    }
};