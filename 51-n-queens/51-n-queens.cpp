class Solution {
public:
    void nqueen(int col, vector<string>& output, vector<vector<string>>& ans, vector<int>& leftRow, vector<int>& lowerDiagonal, vector<int>& upperDiagonal){
        int n = output.size();
        if(col == n){
            ans.push_back(output);    
        }
        
        for(int row=0;row<output.size();row++){
            if(leftRow[row] == 0 && lowerDiagonal[row+col] == 0 && upperDiagonal[n-1+col-row] == 0){
                leftRow[row] = 1;
                lowerDiagonal[row+col] = 1;
                upperDiagonal[n-1+col-row] = 1;
                output[row][col] = 'Q';
                nqueen(col+1,output,ans,leftRow,lowerDiagonal,upperDiagonal);
                output[row][col] = '.';
                upperDiagonal[n-1+col-row] = 0;
                lowerDiagonal[row+col] = 0;
                leftRow[row] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string s(n,'.');
        vector<string> output(n,s);
        vector<int> leftRow(n,0);
        vector<int> upperDiagonal(2*n-1,0);
        vector<int> lowerDiagonal(2*n-1,0);
        nqueen(0,output,ans,leftRow,lowerDiagonal,upperDiagonal);
        return ans;
    }
};