int funct(int i, int j, int m, int n, vector<vector<int>> & a , vector<vector<int>>& b){
    int k = 1;

    int ans = 1;
    while(i+k<m && j+k<n){
        int sum1 = b[i+k][j+k+1]-b[i+k][j];
        int sum2 = a[i+k+1][j+k]-a[i][j+k];
        if(sum1==sum2 && sum2 == k+1){
            ans = (k+1)*(k+1);
        }
        else{
            return ans;
        }
        k++;
    }
    return ans;
}

class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> matrix(m, vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                matrix[i][j] = mat[i][j]-'0';
            }
        }

        vector<vector<int>> TB(m+1, vector<int>(n+1, 0));
        vector<vector<int>> LR(m+1, vector<int>(n+1, 0));

        for(int i=0;i<m;i++){
            int sum = 0;
            for(int j=0;j<n;j++){
                sum+=matrix[i][j];
                if(matrix[i][j] == 0){
                    sum = 0;
                    continue;
                }
                LR[i][j+1] = sum;
            }
        }

        for(int j=0;j<n;j++){
            int sum = 0;
            for(int i=0;i<m;i++){
                sum+=matrix[i][j];
                if(matrix[i][j] == 0){
                    sum = 0;
                    continue;
                }
                TB[i+1][j] = sum;
            }
        }

        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==1){
                    ans = max(ans,funct(i, j, m, n, TB, LR));
                }
            }
        }
        return ans;
    }
};