vector<int> funct(int n){
    vector<int> ans(32,0);
    int i = 0;
    while(n){
        ans[i] = n%2;
        n = n/2;
        i++;
    }
    return ans;
}
class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> binary(size+1,vector<int> (32,0));
        for(int i=0;i<size;i++){
            vector<int> temp = funct(nums[i]);
            for(int j=0;j<32;j++){
            binary[i+1][j] = binary[i][j] + temp[j];
            }
            
        }
        int maxi = 0;
        vector<int> temp(size,0);
        for(int i=size-1;i>=0;i--){
            maxi = maxi | nums[i];
            temp[i] = maxi;
        }
        int ptr1 = 0;
        int ptr2 = 1;
        maxi = nums[0];
        vector<int> ans(size,1);
        while(ptr1<size){
            int tempmaxi = temp[ptr1];
            while(maxi<tempmaxi){
                maxi = maxi | nums[ptr2];
                ptr2++;
            }
            maxi = 0;
            for(int i=0;i<32;i++){
                if(binary[ptr2][i]-binary[ptr1+1][i]){
                    maxi = maxi + pow(2,i);
                }
            }
            if(ptr1<ptr2){
                ans[ptr1] = ptr2-ptr1;
            }
            ptr1++;
        }
        return ans;
    }
};