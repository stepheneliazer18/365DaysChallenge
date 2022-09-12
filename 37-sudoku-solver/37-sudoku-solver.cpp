class Solution {
public:
    bool isValid(int row,int col, char num, vector<vector<char>>& board){
        int x = (row/3) * 3;
        int y = (col/3) * 3;
        for(int i=0;i<9;i++){
            // row
            if(board[row][i] == num) return false;
            
            // col
            if(board[i][col] == num) return false;
            
            // sub box
            if(board[i/3+x][i%3+y] == num) return false;
        }
        return true;
    }
    
    bool sudoku(vector<vector<char>>& board){
        for(int row=0;row<9;row++){
            for(int col=0;col<9;col++){
                if(board[row][col] == '.'){
                    for(char num='1';num<='9';num++){
                        if(isValid(row,col,num,board)){
                            board[row][col] = num;
                            if(sudoku(board)) return true;
                            board[row][col] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        bool flag = sudoku(board);
    }
};