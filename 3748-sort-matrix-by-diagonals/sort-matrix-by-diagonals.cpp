class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> temp;
        for(int r = m-1;r>=0;r--){
            vector<int> temp;
            int i = r;
            int j = 0;
            while(i<m && j<n){
                temp.push_back(grid[i][j]);
                i++;
                j++;
            }
            sort(temp.begin(),temp.end());

            i = r;
            j = 0;
            int k = temp.size()-1;
            while(i<m &&j<n){
                grid[i][j] = temp[k];
                i++;
                j++;
                k--;
            }
            temp.clear();
        }

        for(int r = 1;r<n;r++){
            int i = 0;
            int j = r;
            while(i<m && j<n){
                temp.push_back(grid[i][j]);
                i++;
                j++;
            }
            sort(temp.begin(),temp.end());

            i = 0;
            j = r;
            int k = 0;
            while(i<m &&j<n){
                grid[i][j] = temp[k];
                i++;
                j++;
                k++;
            }
            temp.clear();
        }
        return grid;
    }
};