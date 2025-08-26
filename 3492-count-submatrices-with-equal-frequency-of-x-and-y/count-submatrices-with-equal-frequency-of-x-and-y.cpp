class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<pair<int,int>> matrix(n,{0,0});
        int x = 0,y=0;
        int ans = 0;
        for(int i=0;i<n;i++){
            if(grid[0][i] == 'X'){
                x++;
            }
            else if(grid[0][i] == 'Y'){
                y++;
            }
            matrix[i] = {x,y};
            if((matrix[i].first == matrix[i].second) && matrix[i].first){
                ans++;
            }
        }

        for(int i=1;i<m;i++){
            x = 0,y = 0;
            for(int j=0;j<n;j++){
                if(grid[i][j] == 'X'){
                    x++;
                }
                else if(grid[i][j] == 'Y'){
                    y++;
                }
                int newx = matrix[j].first;
                int newy = matrix[j].second;
                matrix[j] = {x+newx, y+newy};
                if((matrix[j].first == matrix[j].second) && matrix[j].first){
                ans++;
            }
            }
        }
        return ans;
        }

};