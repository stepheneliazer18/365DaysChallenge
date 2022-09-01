class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        vector<int> row(mat.size(), 0);
        vector<int> col(mat[0].size(), 0);
        int count = 0;
        for(int i = 0 ; i < mat.size(); i++){
            for(int j = 0 ; j < mat[0].size(); j++){
                if(mat[i][j] == 1){
                    row[i]++;
                    col[j]++;
                }
            }
        }
        
        for(int i = 0 ; i < mat.size(); i++){
            for(int j = 0 ; j < mat[0].size(); j++){
                if(mat[i][j] == 1){
                    if(row[i] == 1 and col[j] == 1){
                        count++;
                    }
                }
            }
        }
        
        return count;
    }
};