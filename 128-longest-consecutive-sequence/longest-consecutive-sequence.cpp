class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int size = nums.size();
        unordered_map<int,bool> map;
        for(int i=0;i<size;i++){
            map[nums[i]] = true;
        }

        int ans = 0;
        for(int i=0;i<size;i++){
            int l = nums[i];
            int r = nums[i]+1;
            while(map[l]){
                map[l]=false;
                l--;
            }
            while(map[r]){
                map[r] = false;
                r++;
            }

            ans = max(ans,r-l-1);
        }
        return ans;
    }
};