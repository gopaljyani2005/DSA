bool funct(vector<int> & nums,int ele, int k){
    int size = nums.size();
    int ct = 0;
    int i=0;
    while(i<size){
        if(nums[i]<=ele){
            i+=2;
            ct++;
        }
        else{
            i++;
        }
    }
    return ct>=k;
}

class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int size = nums.size();
        int l = *min_element(nums.begin(),nums.end());
        int r = *max_element(nums.begin(),nums.end());
        int ans = 0;
        while(l<=r){
            int mid = (l+r)/2;
            bool check = funct(nums,mid,k);
            if(check){
                ans = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
};