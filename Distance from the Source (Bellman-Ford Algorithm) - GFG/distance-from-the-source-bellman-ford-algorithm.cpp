//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> distance(V,1e8);
        distance[S] = 0;
        
        vector<int> temp;
        for(int i=0;i<V;i++){
            for(auto &it: edges){
                int u = it[0];
                int v = it[1];
                int w = it[2];
                
                if(distance[u] != 1e8 && distance[u] + w < distance[v]){
                    distance[v] = distance[u] + w;
                }
            }
            if(i == V-2) temp = distance;
        }
        
        if(temp != distance) return {-1};
        return distance;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, m;
        cin >> N >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src;
        cin >> src;

        Solution obj;
        vector<int> res = obj.bellman_ford(N, edges, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends