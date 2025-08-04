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
    // reverse(ans.begin(),ans.end());
    return ans;
}
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int size = arr.size();
        vector<vector<int>> perfixSum(size+1,vector<int> (32,0));
        vector<int> sum(32,0);
        for(int i=0;i<size;i++){
            vector<int> temp = NumberToBinary(arr[i]);
            for(int i=0;i<32;i++){
                sum[i]+=temp[i];
            }
            perfixSum[i+1] = sum;
        }

        int q = queries.size();
        vector<int> answer;
        for(int i=0;i<q;i++){
            int l = queries[i][0];
            int r  = queries[i][1];
            int ans = 0;
            for(int i=0;i<31;i++){
                int bit = (perfixSum[r+1][i]-perfixSum[l][i])%2;
                ans = ans + (bit)*pow(2,i);
            }
            answer.push_back(ans);
        }
        return answer;
    }
};