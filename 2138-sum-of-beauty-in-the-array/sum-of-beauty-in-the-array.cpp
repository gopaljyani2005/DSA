class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int size = nums.size();
        int ans = 0;
        priority_queue<int,vector<int>, greater<int>> minheap;
        vector<int> maxelement(size,0);
        for(int i=size-1;i>0;i--){
            minheap.push(nums[i]);
            maxelement[i-1] = minheap.top();
        }
        int maxele = nums[0];
        for(int i=1;i<size-1;i++){
            if(maxele<nums[i] && nums[i]<maxelement[i]){
                ans+=2;
            }
            else if(nums[i-1]<nums[i] && nums[i]<nums[i+1]){
                ans++;
            }
            maxele = max(maxele,nums[i]);
        }
        return ans;
    }
};