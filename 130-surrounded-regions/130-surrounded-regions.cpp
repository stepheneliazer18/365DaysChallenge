class Solution {
public:
    void capture(int i,int j,vector<vector<char>>& arr,int d){
        if(i == arr.size() || j == arr[0].size() || arr[i][j] == 'X') return;
        else arr[i][j] = 'X';
        
        if(d != 3 ) capture(i+1,j,arr,1);
        if(d != 4 ) capture(i,j+1,arr,2);
        if(d != 1 ) capture(i-1,j,arr,3);
        if(d != 2 ) capture(i,j-1,arr,4);
        return;
    }
    bool help(int i,int j,vector<vector<char>>& arr,int d,vector<vector<bool>>& vis){
        if(vis[i][j] == true || arr[i][j] == 'X') return true;
        if(i==arr.size()-1 || j==arr[0].size()-1 || i == 0 || j==0){
            if(arr[i][j] == 'O') return false;
            return true;
        }
        
        vis[i][j] = true;
        
        bool right,left,down,up;
        right = left = down = up = true;
        if(d != 3 ) right = help(i+1,j,arr,1,vis);
        if(d != 4 ) down = help(i,j+1,arr,2,vis);
        if(d != 1 ) left = help(i-1,j,arr,3,vis);
        if(d != 2 ) up = help(i,j-1,arr,4,vis);
        return right && down && left && up;
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                if(board[i][j] == 'X') continue;
                else {
                    if(vis[i][j] == false && help(i,j,board,0,vis)){
                        capture(i,j,board,0);
                    }
                }
            }
        }
    }
};