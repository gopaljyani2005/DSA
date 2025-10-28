class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int size = nums.size();
        vector<int> left(size,0);
        vector<int> right(size,0);
        int sum = 0;
        for(int i=0;i<size;i++){
            sum+=nums[i];
            left[i] = sum;
        }
        sum = 0;
        for(int i=size-1;i>=0;i--){
            sum+=nums[i];
            right[i] = sum;
        }
        
        int ans = 0;
        for(int i=0;i<size;i++){
            if(nums[i]!=0){
                continue;
            }
            else if(left[i]-right[i]==0){
                ans+=2;
            }
            else if(abs(left[i]-right[i])==1){
                ans+=1;
            }
            else{
                continue;
            }
        }
        return ans;
    }
};