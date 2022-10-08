class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> adj1[V];
        
        for(int i=0;i<V;i++){
            int u = i;
            for(auto &v: adj[i]){
                adj1[v].push_back(u);
            }
        }
        
        vector<int> indegree(V,0);
        for(int i=0;i<V;i++){
            for(auto &it: adj1[i]) indegree[it]++;
        }
        
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i] == 0) q.push(i);
        }
        
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            topo.push_back(node);
            
            for(auto &it: adj1[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        
        sort(topo.begin(),topo.end());
        
        return topo;

    }
};