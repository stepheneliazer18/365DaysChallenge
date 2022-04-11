class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<int> vec;
        for(auto &it: grid){
            for(auto &it1: it) vec.push_back(it1);
        }
        k = k % vec.size();
        reverse(vec.begin(),vec.end());
        reverse(vec.begin(),vec.begin()+k);
        reverse(vec.begin()+k,vec.end());
        
        int x = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                grid[i][j] = vec[x];
                x++;
            }
        }
        return grid;
    }
};