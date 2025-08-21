class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> matrix(m, vector<int> (n,0));
        for(int i=0;i<m;i++){
            matrix[i][n-1] = mat[i][n-1];
            for(int j=n-2;j>=0;j--){
                if(mat[i][j]){
                    matrix[i][j] = mat[i][j] + matrix[i][j+1];
                }
            }
        }


        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int row = i;
                int mini = matrix[i][j];
                while(row<m){
                    mini = min(mini,matrix[row][j]);
                    ans = ans + mini;
                    row++;
                }
            }
        }
        return ans;
    }
};