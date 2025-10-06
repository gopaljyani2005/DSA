class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        unordered_map<int,bool> colmap;
        unordered_map<int,bool> rowmap;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    colmap[j] = true;
                    rowmap[i] = true;
                }
            }
        }

        for(int i=0;i<m;i++){
            if(rowmap[i]){
                for(int j=0;j<n;j++){
                    matrix[i][j] = 0;
                }
            }
        }

        for(int j=0;j<n;j++){
            if(colmap[j]){
                for(int i=0;i<m;i++){
                    matrix[i][j] = 0;
                }
            }
        }
        return ;
    }
};