vector<int> NumberToBinary(int num){
    vector<int> ans;
    while(num){
        ans.push_back(num%2);
        num/=2;
    }
    int size = ans.size();
    for(int i=size;i<32;i++){
        ans.push_back(0);
    }
    return ans;
}
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int k) {
        int xor1 = 0;
        int size = nums.size();
        for(int i=0;i<size;i++){
            xor1 = xor1 ^ nums[i];
        }

        vector<int> ans(size,0);
        for(int i=0;i<size;i++){
            vector<int> temp = NumberToBinary(xor1);
            bool flag = false;
            int answer = 0;
            for(int j=k-1;j>=0;j--){
                if(temp[j]==0){
                    flag = true;
                    answer = answer + pow(2,j);
                }
            }

            ans[i] = answer;
            xor1 = xor1 ^ nums[size-i-1];
        }
        return ans;
    }
};