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
        
        vector<vector<int>> vec(10,vector<int>(10,0));
        
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                if(valid(i,j,board)){
                    for(int x=i;x<i+3;x++){
                        for(int y=j;y<j+3;y++){
                            for(int a=0;a<9;a++){
                                if(a==y || board[x][a]=='.') continue;
                                if(board[x][y] == board[x][a])return false;
                            }
                            for(int a=0;a<9;a++){
                                if(a==x || board[a][y]=='.') continue;
                                if(board[x][y] == board[a][y])return false;
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