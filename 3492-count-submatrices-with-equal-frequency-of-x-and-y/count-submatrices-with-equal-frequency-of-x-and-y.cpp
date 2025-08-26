class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<pair<int,int>>> matrix(m,vector<pair<int,int>> (n,{0,0}));
        int x = 0,y=0;
        int ans = 0;
        for(int i=0;i<n;i++){
            if(grid[0][i] == 'X'){
                x++;
            }
            else if(grid[0][i] == 'Y'){
                y++;
            }
            matrix[0][i] = {x,y};
            if((matrix[0][i].first == matrix[0][i].second) && matrix[0][i].first){
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
                int newx = matrix[i-1][j].first;
                int newy = matrix[i-1][j].second;
                matrix[i][j] = {x+newx, y+newy};
                if((matrix[i][j].first == matrix[i][j].second) && matrix[i][j].first){
                ans++;
            }
            }
        }
        return ans;
        }

};