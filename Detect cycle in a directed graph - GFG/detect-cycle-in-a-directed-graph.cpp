// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    vector<int> bfs(vector<int> adj[], vector<int>& indegree){
	    queue<int> q;
	    vector<int> res;
	    for(int i=0;i<indegree.size();i++) if(indegree[i]==0)q.push(i);
	    
	    while(!q.empty()){
	        int node = q.front();
	        res.push_back(node);
	        q.pop();
	        for(auto &it: adj[node]){
	            indegree[it]-=1;
	            if(indegree[it]==0)q.push(it);
	        }
	    }
	    return res;
	}
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> indegree(V,0);
	    for(int i=0;i<V;i++){
	        for(auto &it: adj[i])indegree[it]++;
	    }

	    vector<int> res = bfs(adj,indegree);
	    return res.size()!=V;
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