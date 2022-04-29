class Solution {
public:
    
    bool dfs(int source, int color, vector<int> &seen, vector<vector<int>>& graph){
        seen[source] = color;

        for(auto nbr: graph[source]){
            if(seen[nbr] == 0){
                bool subProb = dfs(nbr, 3 - color, seen, graph);
                if(!subProb) return false;
            }
            else if(color == seen[nbr]) return false;
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> seen(V, 0);

        int color = 1;
        for(int i=0;i<V;i++){
            if(!seen[i] and !dfs(i, color, seen, graph)) return false;
        }
    
        return true;
    }
};
