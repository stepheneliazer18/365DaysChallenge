class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int co=0;
        int r=grid.size()-1;
        int c=0;
        int m=grid[0].size()-1;
       
        while(c<grid[0].size() && r>=0){
            if(grid[r][c]<0){
                co=co+(m-(c-1));
                r--;    
            }
            else if(grid[r][c]>0){
                c++;
                
            }
            else{
                c++;
            }
        }
        return co;
        
    }
};