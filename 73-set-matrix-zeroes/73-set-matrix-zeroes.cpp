class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        bool rowBool = false;
        bool colBool = false;
        for(int i=0;i<m;i++){
            if(matrix[i][0] == 0) colBool = true;
            for(int j=1;j<n;j++){
                if(i == 0 && matrix[i][j]==0){
                    rowBool = true;
                }
                if(i>0 && matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }                
            }
        }
        
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==0 && rowBool) matrix[i][j] = 0;
                if(j==0 && colBool) matrix[i][j] = 0;
                if(matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j]=0;
            }
        }
    }
};
