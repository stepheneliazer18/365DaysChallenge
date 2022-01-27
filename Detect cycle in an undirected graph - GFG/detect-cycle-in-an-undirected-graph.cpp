// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    public:
    bool isCyclic(int i, vector<int> adj[], vector<bool> vis){
        queue<pair<int,int>> q;
        q.push({i,-1});
        vis[i] = true;
        while(!q.empty()){
            int node = q.front().first;
            int prev = q.front().second;
            q.pop();
            
            for(auto &it: adj[node]){
                if(vis[it] && it!=prev) return true;
                if(!vis[it]){
                    q.push({it,node});
                    vis[it] = true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> vis(V,false);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(isCyclic(i,adj,vis)) return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends