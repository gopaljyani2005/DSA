int funct(int i, int j, vector<vector<int>> & grid, vector<vector<bool>>& visited){
    int m = grid.size();
    int n = grid[0].size();
    queue<pair<int,int>> q;
    q.push({i,j});
    visited[i][j] = true;
    int ct = 1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(x+1<m && !visited[x+1][y] && grid[x+1][y]){
            visited[x+1][y] = true;
            ct++;
            q.push({x+1,y});
        }

        if(x-1>=0 && !visited[x-1][y] && grid[x-1][y]){
            visited[x-1][y] = true;
            ct++;
            q.push({x-1,y});
        }

        if(y+1<n && !visited[x][y+1] && grid[x][y+1]){
            visited[x][y+1] = true;
            ct++;
            q.push({x,y+1});
        }

        if(y-1>=0 && !visited[x][y-1] && grid[x][y-1]){
            visited[x][y-1] = true;
            ct++;
            q.push({x,y-1});
        }
        
    }
    return ct;
}

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        int ans = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] && (!visited[i][j])){
                    int  temp = funct(i,j,grid,visited);
                    ans = max(temp,ans);
                }
            }
        }
        return ans;
    }
};