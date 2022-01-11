/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 */

// @lc code=start
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        set<int> row;
        set<int> col;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        for(auto &it: row){
            for(int i=0;i<n;i++){
                matrix[it][i] = 0;
            }
        }
        for(auto &it: col){
            for(int i=0;i<m;i++){
                matrix[i][it] = 0;
            }
        }
    }
};
// @lc code=end

