class Solution {
public:
    void help(int i,int j,vector<vector<char>>& grid){
        if(i==-1 || j==-1 || i==grid.size() || j==grid[0].size()) return;
        if(grid[i][j] == '0') return;
        
        grid[i][j] = '0';
        help(i+1,j,grid);
        help(i,j+1,grid);
        help(i-1,j,grid);
        help(i,j-1,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        for(auto &it: grid){
            for(auto &it1: it) cout<<it1<<" ";
            cout<<endl;
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                cout<<i<<" "<<j<<endl;
                if(grid[i][j] == '1'){
                    help(i,j,grid);
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
};