

class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        long long ans = 0;
        int perfix = 0;
        unordered_map<int,int> map;
        map[0]++;
        for(int i=0;i<nums.size();i++){
            perfix = perfix ^ nums[i];
            if(map[perfix]){
                ans = ans + map[perfix];
            }
            map[perfix]++;
        }
        return ans;
    }
};