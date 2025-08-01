class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        ans.push_back({1});
        if(n==1){
            return ans;
        }
        ans.push_back({1,1});
        for(int i=2;i<n;i++){
            vector<int> temp;
            temp.push_back(1);
            vector<int> last = ans[i-1];
            for(int i=1;i<last.size();i++){
                temp.push_back(last[i-1]+ last[i]);
            }
            temp.push_back(1);
            ans.push_back(temp);
        }
        return ans;
    }
};