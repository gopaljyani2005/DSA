class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> ans;
        bool flag = false;
        for(int r = 0;r < m+n -1; r++){
            int i,j;
            if(r>=m){
                i = m-1;
                j = r-m+1;
            }
            else{
                i = r;
                j = 0;
            }
            vector<int> temp;
            while(i>=0 && j<n){
                temp.push_back(mat[i][j]);
                i--;
                j++;
            }
            if(flag){
                reverse(temp.begin(),temp.end());
                flag = false;
            }
            else{
                flag = true;
            }
            int size = temp.size();
            for(int i=0;i<size;i++){
                ans.push_back(temp[i]);
            }
        }
        return ans;
    }
};