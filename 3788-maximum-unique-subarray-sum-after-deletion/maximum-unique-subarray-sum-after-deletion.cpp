class Solution {
public:
    int maxSum(vector<int>& nums) {
        int size = nums.size();
        unordered_map<int,bool> map;
        int sum = 0;
        for(int i=0;i<size;i++){
            if(nums[i]<0){
                continue;
            }
            else if(map[nums[i]]){
                continue;
            }
            else{
                map[nums[i]] = true;
                sum+=nums[i];
            }
        }
        if(sum==0){
            return *max_element(nums.begin(),nums.end());
        }
        return sum;
    }
};