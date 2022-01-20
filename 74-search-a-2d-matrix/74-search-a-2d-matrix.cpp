class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int left = 0;
        int right = matrix.size()*matrix[0].size()-1;
        
        while(left<=right){
            int mid = (left+right)/2;
            
            int mid_val = matrix[mid/matrix[0].size()][mid%matrix[0].size()];
            
            if(mid_val == target)return true;
            
            else if(target < mid_val) right = mid-1;
            else left = mid+1;
        }
        return false;
        
    }
};