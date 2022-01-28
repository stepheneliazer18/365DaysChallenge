// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool helper(int node,vector<int>&color,vector<int>adj[])
   {
       queue<int>q;
       q.push(node);
       color[node]=1;
       while(!q.empty())
       {
           int src=q.front();
           q.pop();
           for(auto it:adj[src])
           {
               if(color[it]==-1)
               {
                   color[it]=1-color[src];
                   q.push(it);
               }
               else if(color[it]==color[src])
               {
                   return false;
               }
           }
       }
       return true;
   }
bool isBipartite(int v, vector<int>adj[]){
    vector<int>color(v,-1);
    for(int i=0;i<v;i++)
    {
        if(color[i]==-1)
        {
            if(!helper(i,color,adj))return false;
        }
    }
    return true;
}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends