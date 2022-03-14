class Solution {
public:
    bool help(int i,int j,vector<vector<char>>& arr, string target, string str,int ind,vector<vector<bool>>& vis){
        if(i == arr.size() || j==arr[0].size() || i==-1 || j==-1 || vis[i][j] || ind == target.size()) return false;

        if(target[ind] == arr[i][j]){
            
            vis[i][j] = true;
            str += arr[i][j];
            
            if(ind == target.size()-1){
                cout<<"ind = "<<ind<<endl;
                cout<<"str = "<<str<<endl;
                for(auto it: vis){
                    for(auto it1: it) cout<<it1<<" ";cout<<endl;
                }
                if(target == str) return true;
                else return false;
            }
            
            bool right = help(i,j+1,arr,target,str,ind+1,vis);
            // vis[i][j] = false;
            bool down = help(i+1,j,arr,target,str,ind+1,vis);
            // vis[i][j] = false;
            bool left = help(i,j-1,arr,target,str,ind+1,vis);
            // vis[i][j] = false;
            bool up = help(i-1,j,arr,target,str,ind+1,vis);
            // vis[i][j] = false;

            if(!right && !left && !down && !up){
                str.pop_back();
                vis[i][j] = false;
            }

            return right || down || left || up;
        } 
        else return false;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        cout<<"m = "<<m<<endl;
        cout<<"n = "<<n<<endl;
        
        cout<<"initial"<<endl;
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        for(auto it: vis){
            for(auto it1: it) cout<<it1<<" ";
            cout<<endl;
        }
        cout<<"done"<<endl;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == word[0]){
                    if(help(i,j,board,word,"",0,vis)) return true;
                }
            }
        }
        return false;
    }
};

// [["A","B","C","E"],["S","F","E","S"],["A","D","E","E"]]
// "ABCESEEEFS"
// [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
// "ABCCED"
// [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
// "SEE"
// [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
// "ABCB"
