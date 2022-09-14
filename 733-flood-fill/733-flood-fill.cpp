class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size();
        int n = image[0].size();
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int color = image[sr][sc];
        image[sr][sc] = newColor;
        if(color == newColor) return image;
        
        vector<int> dx{0,1,0,-1};
        vector<int> dy{1,0,-1,0};
        
        while(!q.empty()){
            int nodex = q.front().first;
            int nodey = q.front().second;
            q.pop();
            
            for(int i=0;i<4;i++){
                int newRow = nodex + dx[i];
                int newCol = nodey + dy[i];
                
                if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && image[newRow][newCol] == color){
                    q.push({newRow,newCol});
                    image[newRow][newCol] = newColor;
                }
            }
        }
        
        return image;
    }
};