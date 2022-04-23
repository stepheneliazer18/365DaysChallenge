class Solution {
public:
    void makeItZero(int x,int y, vector<vector<int>>& matrix){
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i=0;i<n;i++) matrix[x][i] = 0;
        for(int i=0;i<m;i++) matrix[i][y] = 0;
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> temp(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == 0){
                    makeItZero(i,j,temp);
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(temp[i][j] == 0) matrix[i][j] = 0;
            }
        }
    }
};