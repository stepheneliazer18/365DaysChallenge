class Solution {
private:
    bool isvalid(int x, int y, int n, int m){
        return x >= 0 && y >= 0 && x < n && y < m;
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        pair<int,int> source = {0,0};
        pair<int,int> destination = {n-1,m-1};
        
        vector<int> dx{0,1,1,1,0,-1,-1,-1};
        vector<int> dy{1,1,0,-1,-1,-1,0,1};
        
        vector<vector<int>> distance(n,vector<int>(m,INT_MAX));
        set<pair<int,pair<int,int>>> st;

        st.insert({1,source});
        distance[source.first][source.second] = 1;
        
        while(!st.empty()){
            auto node = *(st.begin());
            int dist = node.first;
            int x = node.second.first;
            int y = node.second.second;
            st.erase(node);
            
            for(int i=0;i<8;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(isvalid(nx,ny,n,m) && !grid[nx][ny] && dist + 1 < distance[nx][ny]){
                    if(distance[nx][ny] != INT_MAX) st.erase({distance[nx][ny],{nx,ny}});
                    st.insert({dist+1,{nx,ny}});
                    distance[nx][ny] = dist+1;
                }
            }
        }
        int ans = distance[destination.first][destination.second];
        if(ans == INT_MAX || grid[0][0] || grid[n-1][m-1]) return -1;
        return ans;
    }
};