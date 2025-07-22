class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int size = nums.size();
        int sum = 0;
        int maxi = 0;
        int l = 0;
        unordered_map<int,bool> map;
        for(int i=0;i<size;i++){
            if(map[nums[i]]){
                while(l<size && map[nums[i]]){
                    sum-=nums[l];
                    map[nums[l]] = false;
                    l++;
                }
                sum+=nums[i];
                maxi = max(maxi,sum);
                map[nums[i]] = true;   
            }
            else{
                sum+=nums[i];
                maxi = max(maxi,sum);
                map[nums[i]] = true;
            }
        }
        return maxi;
    }
};