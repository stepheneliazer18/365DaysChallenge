class Solution {
public:
    bool isvalid(int row, int col, vector<string>& output){
        int i = row;
        int j = col;

        // left
        while(j >= 0){
            if(output[row][j] == 'Q') return false;
            j--;
        }
        
        // left up diagonal
        i = row;
        j = col;
        while(row >= 0 && col >= 0){
            if(output[row][col] == 'Q') return false;
            row--;col--;
        }
        
        // left down diagonal
        while(i < output.size() && j >= 0){
            if(output[i][j] == 'Q') return false;
            i++;j--;
        }
        
        return true;
    }
    void nqueen(int col, vector<string>& output, vector<vector<string>>& ans){
        if(col == output.size()){
            ans.push_back(output);    
        }
        
        for(int row=0;row<output.size();row++){
            if(isvalid(row,col,output)){
                output[row][col] = 'Q';
                nqueen(col+1,output,ans);
                output[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string s(n,'.');
        vector<string> output(n,s);
        nqueen(0,output,ans);
        return ans;
    }
};