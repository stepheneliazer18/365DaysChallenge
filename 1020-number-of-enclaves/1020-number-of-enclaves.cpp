class Solution {
private:
    bool isvalid(int i, int j, int m, int n){
        return i >= 0 && i < m && j >= 0 && j < n;
    }
    void dfs(int row, int col, vector<vector<int>>& visited, vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();

        visited[row][col] = 1;

        vector<int> dx{0,1,0,-1};
        vector<int> dy{1,0,-1,0};

        for(int i=0;i<4;i++){
            int nr = row + dx[i];
            int nc = col + dy[i];

            if(isvalid(nr,nc,m,n) && !visited[nr][nc] && grid[nr][nc] == 1){
                dfs(nr,nc,visited,grid);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> visited(m,vector<int>(n,0));
        
        for(int j=0;j<n;j++){
            if(grid[0][j] == 1 && !visited[0][j]){
                dfs(0,j,visited,grid);
            }
            if(grid[m-1][j] == 1 && !visited[m-1][j]){
                dfs(m-1,j,visited,grid);
            }
        }
        
        for(int i=0;i<m;i++){
            if(grid[i][0] == 1 && !visited[i][0]){
                dfs(i,0,visited,grid);
            }
            if(grid[i][n-1] == 1 && !visited[i][n-1]){
                dfs(i,n-1,visited,grid);
            }
        }
        
        int sum = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j] && grid[i][j] == 1) sum++;
            }
        }
        return sum;
    }
};