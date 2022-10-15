//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = 1000000007;
        vector<pair<int,int>> adj[n];
        
        for(auto &it: roads){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0});
        
        vector<int> distance(n,INT_MAX);
        distance[0] = 0;
        
        vector<int> ways(n,0);
        ways[0] = 1;
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            
            int dist = it.first;
            int node = it.second;
            
            for(auto &it: adj[node]){
                int v = it.first;
                int w = it.second;
                
                if(dist + w < distance[v]){
                    ways[v] += ways[node];
                    distance[v] = dist + w;
                    pq.push({dist + w, v});
                }
                else if(dist + w == distance[v]) ways[v] += ways[node];
            }
        }
        
        return ways[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends