void funct(vector<int> & nums, int index, vector<int> & ans,int val){
    if(nums.size()==index){
        ans.push_back(val);
        return ;
    }
    funct(nums,index+1,ans,val | nums[index]);
    funct(nums,index+1,ans, val);
    return;
}

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        vector<int> ans;
        funct(nums,0,ans,0);
        int maxi = *max_element(ans.begin(),ans.end());
        int ct = 0;
        for(int i=0;i<ans.size();i++){
            if(ans[i]==maxi){
                ct++;
            }
        }
        return ct;
    }
};