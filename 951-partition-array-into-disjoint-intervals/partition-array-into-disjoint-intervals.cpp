class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int size = nums.size();
        priority_queue<int,vector<int>, greater<int>> minheap;

        vector<int> maxelement(size,0);
        for(int i=size-1;i>0;i--){
            minheap.push(nums[i]);
            maxelement[i-1] = minheap.top();
        }

        int maxi = nums[0];
        for(int i=0;i<size-1;i++){
            maxi = max(maxi, nums[i]);
            if(maxi<=maxelement[i]){
                return i+1;
            }
        }
        return 0;
    }
};