class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        
        vector<vector<int>>curr=board;
        int di[]={0,-1,-1,-1,0,1,1,1};        
        int dj[]={-1,-1,0,1,1,1,0,-1};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int live=0;
                for(int k=0;k<8;k++){
                    if(i+di[k]>=0 && i+di[k]<n && j+dj[k]<m && j+dj[k]>=0){
                        if(curr[i+di[k]][j+dj[k]]==1){
                            live++;
                        }
                    }
                }
            
                if(live<2 || live>3)board[i][j]=0;
                else
                if(live==3)board[i][j]=1;
                      
            }
        }        
    }
};