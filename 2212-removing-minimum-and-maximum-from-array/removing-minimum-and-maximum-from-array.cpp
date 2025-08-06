pair<int,int> findIndex(vector<int> & nums){
    int size = nums.size();
    int mini = *min_element(nums.begin(),nums.end());
    int maxi = *max_element(nums.begin(),nums.end());

    int minindex,maxindex;
    for(int i=0;i<size;i++){
        if(mini == nums[i]){
            minindex = i;
        }
        else if(maxi == nums[i]){
            maxindex = i;
        }
    }
    return make_pair(min(minindex,maxindex),max(minindex,maxindex));
}

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int size = nums.size();
        pair<int,int> index = findIndex(nums);
        int i1 = index.first;
        int i2 = index.second;

        int x1 = i1+1;
        int x2 = i2+1;
        int x3 = size-i2;
        int x4 = size-i1;
        return min(x1+x3, min(x2,x4));
    }
};