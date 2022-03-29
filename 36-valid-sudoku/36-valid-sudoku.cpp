class Solution {
public:
    bool valid(int i,int j, vector<vector<char>>& board){
        map<char,int> mp;
        for(int x=i;x<i+3;x++){
            for(int y=j;y<j+3;y++){
                if(board[x][y]=='.') continue;
                mp[board[x][y]]++;
                if(mp[board[x][y]] > 1) return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(auto &it: board){
            for(auto &it1: it) cout<<it1<<" ";cout<<endl;
        }
        
        vector<vector<int>> vec(10,vector<int>(10,0));
        
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                if(valid(i,j,board)){
                    for(int x=i;x<i+3;x++){
                        for(int y=j;y<j+3;y++){
                            for(int a=0;a<9;a++){
                                if(a==y || board[x][a]=='.') continue;
                                if(board[x][y] == board[x][a]){
                                    cout<<x<<y<<endl;
                                    cout<<x<<a<<endl;
                                    return false;
                                }
                            }
                            for(int a=0;a<9;a++){
                                if(a==x || board[a][y]=='.') continue;
                                if(board[x][y] == board[a][y]){
                                    cout<<"hey"<<endl;
                                    cout<<x<<y<<endl;
                                    cout<<a<<y<<endl;
                                    return false;
                                } 
                            }
                        }
                    }
                }
                else return false;
            }
        }
        return true;
    }
};

/*

[["8","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]

*/