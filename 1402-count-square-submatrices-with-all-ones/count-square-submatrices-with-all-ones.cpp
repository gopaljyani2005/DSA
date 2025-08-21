class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> matrix1(m+1,vector<int>(n,0));
        vector<vector<int>> matrix2(m,vector<int> (n+1,0));

        for(int j=0;j<n;j++){
            for(int i=0;i<m;i++){
                matrix1[i+1][j] = matrix[i][j] + matrix1[i][j];
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                matrix2[i][j+1] = matrix[i][j] + matrix2[i][j];
            }
        }

        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int row = i;
                int col = j;
                while(row < m && col < n){
                    int temp1 = matrix1[row+1][col] - matrix1[i][col];
                    int temp2 = matrix2[row][col+1] - matrix2[row][j];
                    if(temp1 == row-i + 1 && temp2 == row - i + 1){
                        row++;
                        col++;
                        ans++;
                    }
                    else{
                        break;
                    }
                }
            }
        }
        return ans;
    }
};