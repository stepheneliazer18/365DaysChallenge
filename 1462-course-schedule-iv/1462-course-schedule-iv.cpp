class Solution {
private:
    bool cango(int src, int target, vector<int> adj[], vector<int>& visited){
        visited[src] = 1;
        
        if(src == target) return true;
        
        for(auto &it: adj[src]){
            if(!visited[it]){
                if(cango(it,target,adj,visited)) return true;
            }
        }
        
        return false;
    }
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int n = numCourses;
        vector<int> adj[n];
        
        for(auto &it: prerequisites){
            int u = it[0];
            int v = it[1];
            
            adj[u].push_back(v);
        }
        
        vector<vector<bool>> reachable(n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            queue<int> q;
            q.push(i);
            
            while(!q.empty()){
                int node = q.front();
                q.pop();
                
                for(auto &it: adj[node]){
                    if(!reachable[i][it]){
                        q.push(it);
                        reachable[i][it] = true;
                    }
                }
            }
        }
        
        vector<bool> res;
        for(auto &it: queries){
            int u = it[0];
            int v = it[1];
            
            res.push_back(reachable[u][v]);
        }
        
        return res;
    }
};

/*

2
[[1,0]]
[[0,1],[1,0]]
2
[]
[[1,0],[0,1]]
3
[[1,2],[1,0],[2,0]]
[[1,0],[1,2]]
5
[[0,1],[1,2],[2,3],[3,4]]
[[0,4],[4,0],[1,3],[3,0]]
4
[[2,3],[2,1],[0,3],[0,1]]
[[0,1],[0,3],[2,3],[3,0],[2,0],[0,2]]

*/