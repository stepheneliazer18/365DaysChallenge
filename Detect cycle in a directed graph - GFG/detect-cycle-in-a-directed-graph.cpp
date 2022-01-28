// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool isCyclic(int i, vector<int> adj[], vector<bool>& vis,vector<bool>& visdfs){
        vis[i] = true;
        visdfs[i] = true;
        for(auto &it: adj[i]){
            if(!vis[it]){
                if(isCyclic(it,adj,vis,visdfs)) return true;
            }
            if(visdfs[it]) return true;
        }
        visdfs[i] = false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> vis(V,false);
        vector<bool> visdfs(V,false);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(isCyclic(i,adj,vis,visdfs)) return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends