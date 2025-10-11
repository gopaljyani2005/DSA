class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        map<int,int> map1;
        for(int i=0;i<nums.size();i++){
            if (map1.find(target - nums[i]) != map1.end()) {
                return {map1[target - nums[i]] - 1, i};
            }
            else {
                map1[nums[i]] = i + 1;
            }

                    }
        return {};
    }
};