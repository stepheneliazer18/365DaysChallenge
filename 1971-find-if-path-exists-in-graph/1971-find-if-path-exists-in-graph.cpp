class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        vector<int> adj[n];
        for(auto &it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        queue<int> q;
        q.push(source);
        vector<bool> vis(n,false);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            vis[node] = true;
            
            if(node == destination) return true;
            
            for(auto &it: adj[node]){
                if(!vis[it]){
                    q.push(it);
                }
            }
        }
        return false;
    }
};