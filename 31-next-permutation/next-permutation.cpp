class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        vector<int> temp;
        int i = size-1;
        while(i>=0){
            int ele = INT_MAX;
            int index = i;
            for(int j=0;j<size-i-1;j++){
                if(temp[j]>nums[i] && temp[j]<=ele){
                    ele = temp[j];
                    index = size-j-1;
                }
            }
            swap(nums[i],nums[index]);
            if(index!=i){
                vector<int> temp2;
                for(int j=i+1;j<size;j++){
                    temp2.push_back(nums[j]);
                }
                sort(temp2.begin(),temp2.end());
                for(int j=i+1;j<size;j++){
                    nums[j] = temp2[j-i-1];
                }
                return ;
            }
            temp.push_back(nums[i]);
            i--;
        }
        reverse(nums.begin(),nums.end());
        return ;
    }
};