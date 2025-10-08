class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(); // size of the matrix 
        /// this solution is without extra space 

        for(int i=0;i<(n)/2;i++){
            for(int j=0;j<(n+1)/2;j++){
                int temp = matrix[j][n-1-i];
                matrix[j][n-1-i] = matrix[i][j];

                int temp1 = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = temp;
                temp = temp1;

                temp1 = matrix[n-1-j][i];
                matrix[n-1-j][i] = temp;
                temp = temp1;

                matrix[i][j] = temp;
            }
        }
        return ;
    }
};