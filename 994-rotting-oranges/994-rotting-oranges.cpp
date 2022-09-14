class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<int> dx{0,1,0,-1};
        vector<int> dy{1,0,-1,0};
        
        queue<pair<int,int>> q;
        
        int oranges = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1) oranges++;
                if(grid[i][j] == 2){
                    q.push({i,j}); 
                }
            }
        }
        
        int cnt = -1;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                int nodex = q.front().first;
                int nodey = q.front().second;
                q.pop();
                
                for(int i=0;i<4;i++){
                    int nr = nodex + dx[i];
                    int nc = nodey + dy[i];
                    
                    if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1){
                        grid[nr][nc] = 2;
                        oranges--;
                        q.push({nr,nc});
                    }
                }
            }   
            cnt++;
        }
        
        if(oranges) return -1;
        return cnt == -1 ? 0 : cnt;
    }
};

/*
[[2,1,1],[0,1,1],[1,0,1]]
[[0,2]]
[[2,1,1],[1,1,1],[0,1,2]]
*/