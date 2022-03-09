class Solution {
public:
    void capture(int i,int j,vector<vector<char>>& arr,vector<vector<bool>>& vis){
        if(i == arr.size() || j == arr[0].size() || i== -1 || j==-1 || arr[i][j] == 'X') return;
        else arr[i][j] = '1';
        if(vis[i][j] == true) return;
        cout<<i<<" "<<j<<endl;
        
        vis[i][j] = true;
        
        capture(i+1,j,arr,vis);
        capture(i,j+1,arr,vis);
        capture(i-1,j,arr,vis);
        capture(i,j-1,arr,vis);
        return;
    }
    
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0 || i==m-1 || j==n-1){
                    if(board[i][j] == 'O'){
                        capture(i,j,board,vis);
                    }
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++) cout<<board[i][j]<<" ";
            cout<<endl;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == '1') board[i][j] = 'O';
            }
        }
    }
};