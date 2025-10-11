int funct(int s, int e, vector<int> & nums, int & ans){
    if(s==e){
        return 0;
    }
    else{
        int mid = (s+e)/2;
        int left = funct(s, mid, nums, ans);
        int right = funct(mid+1, e, nums, ans);
        int ptr1 = s;
        int ptr2 = mid+1;
        for(int j=ptr2;j<=e;j++){
            long long temp = nums[j];
            while(ptr1<=mid && nums[ptr1]<=2*temp){
                ptr1++;
            }
            ans = ans + (mid-ptr1+1);
        }

        sort(nums.begin() + s, nums.begin() + e+1);


        return 0;
    }
}
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int ans = 0;
        funct(0, nums.size()-1, nums, ans);
        for(int i=0;i<nums.size();i++){
            cout<<nums[i]<<" ";
        }
        return ans;
    }
};