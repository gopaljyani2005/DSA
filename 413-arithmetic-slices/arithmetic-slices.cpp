class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans = 0;
        int size = nums.size();
        int e = 1;
        if(size<3){
            return 0;
        }
        int diff = nums[1]-nums[0];
        for(int i=1;i<size;i++){
            int tempdiff = nums[i]-nums[i-1];
            if(diff == tempdiff){
                e++;
            }
            else{
               ans = ans + (e-1)*(e-2)/2;
               diff = tempdiff;
               e = 2; 
            }
        }
        ans = ans + (e-1)*(e-2)/2;
        return ans;
    }
};