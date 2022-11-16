class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> matrix(n,vector<int>(n,INT_MAX));
        
        for(int i=0;i<n;i++) matrix[i][i] = 0;
        for(auto &it: edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            
            matrix[u][v] = w;
            matrix[v][u] = w;
        }
        
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(matrix[i][k] == INT_MAX || matrix[k][j] == INT_MAX) continue;
                    matrix[i][j] = min(matrix[i][k] + matrix[k][j], matrix[i][j]);
                }
            }
        }

        int ans = -1;
        int mini = n;
        for(int i=0;i<n;i++){
            int cnt = 0;
            for(int j=0;j<n;j++){
                if(matrix[i][j] <= distanceThreshold) cnt++;
            }
            
            if(cnt <= mini){
                mini = cnt;
                ans = i;
            }
        }
        
        return ans;
    }
};