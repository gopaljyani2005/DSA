class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int left = 0;
        int right = n-1;
        int top = 0;
        int bottom = m-1;

        while(left<n){
            int sum = 0;
            for(int i=0;i<m;i++){
                sum+=grid[i][left];
            }
            if(sum==0){
                left++;
            }
            else{
                break;
            }
        }

        while(right>left){
            int sum = 0;
            for(int i=0;i<m;i++){
                sum+=grid[i][right];
            }
            if(sum==0){
                right--;
            }
            else{
                break;
            }
        }

        while(top<m){
            int sum = 0;
            for(int j = 0; j < n ; j++){
                sum+=grid[top][j];
            }
            if(sum==0){
                top++;
            }
            else{
                break;
            }
        }

        while(bottom>top){
            int sum = 0;
            for(int j = 0;j<n ; j++){
                sum+=grid[bottom][j];
            }
            if(sum==0){
                bottom--;
            }
            else{
                break;
            }
        }
        cout<<left<<right<<top<<bottom<<endl;
        return (right-left+1)*(-top+bottom+1);


    }
};