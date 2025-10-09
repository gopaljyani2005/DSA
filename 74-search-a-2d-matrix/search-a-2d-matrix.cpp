class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int s = 0;
        int e = m*n-1;

        while(s<=e){
            // first we find the row and column number 
            int mid = (s+e)/2;

            int row = mid/n;
            int col = mid - row*n;
            cout<<row<<" "<<col<<endl;
            int ele = matrix[row][col];

            if(ele == target){
                return true;
            }
            else if(ele> target){
                e = mid-1;
            }
            else{
                s = mid + 1;
            }
        }
        return false;
    }
};