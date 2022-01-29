// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	stack<int> st;
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
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    
	    vector<int> indegree(V,0);
	    for(int i=0;i<V;i++){
	        for(auto &it: adj[i])indegree[it]++;
	    }

	    vector<int> res = bfs(adj,indegree);
	    return res;
	}
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends