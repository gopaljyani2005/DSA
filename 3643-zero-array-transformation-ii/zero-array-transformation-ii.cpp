class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int size = nums.size();
        int q = queries.size();
        int ptr1 = 0;
        int ptr2 = 0;
        vector<long long > temp(size+1,0);
        long long val = 0;
        while(ptr1<size){
            val+=temp[ptr1];
            while(val<nums[ptr1]){
                if(ptr2>=q){
                    return -1;
                }
                int l = queries[ptr2][0];
                int r = queries[ptr2][1];
                int v = queries[ptr2][2];
                if(ptr1>r){
                    ptr2++;
                    continue;
                }         
                else if(ptr1>=l && ptr1<=r){
                    val+=v;
                    temp[r+1]-=v;
                }
                else{
                    temp[l]+=v;
                    temp[r+1]-=v;
                }
                ptr2++;
            }
            ptr1++;
        }
        return ptr2;
    }
};