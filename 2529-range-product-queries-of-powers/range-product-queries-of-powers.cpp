int mod = pow(10,9) + 7;
class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> binary;
        while(n){
            binary.push_back(n%2);
            n = n/2;
        }
        // reverse(binary.begin(),binary.end());

        vector<int> temp;
        for(int i=0;i<binary.size();i++){
            if(binary[i]==1){
                temp.push_back(i);
            }
        }

        int size = temp.size();
        vector<int> perfixSum(size+1,0);
        int sum = 0;
        for(int i=0;i<size;i++){
            sum+=temp[i];
            perfixSum[i+1] = sum;
        } 

        int q  = queries.size();
        vector<int> ans(q,0);
        for(int i=0;i<q;i++){
            int l = queries[i][0];
            int r = queries[i][1];
            int power = perfixSum[r+1]-perfixSum[l];
            cout<<power<<endl;
            long long answer = 1;
            while (power >= 31) {
                long long powval = 1LL << 30; 
                answer = (answer * powval % mod) % mod;
                power -= 30;
            }
            answer = (answer * (1LL << power)) % mod;
            ans[i] = answer;
        }  
        return ans;
    }
};