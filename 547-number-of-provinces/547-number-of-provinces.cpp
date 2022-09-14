class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& visited, int V){
        visited[node] = 1;
        
        for(int i=0;i<V;i++){
            if(adj[node-1][i] == 1 && i != node-1 && !visited[i+1]){
                dfs(i+1,adj,visited,V);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& adj) {
        int V = adj.size();
        int cnt = 0;
        
        vector<int> visited(V+1,0);
        
        for(int i=1;i<=V;i++){
            if(!visited[i]){
                dfs(i,adj,visited, V);
                cnt++;
            }
        }
        
        return cnt;
    }
};