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
        
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        pq.push({0,0});
        
        vector<long long> distance(n,1e18);
        distance[0] = 0;
        
        vector<int> ways(n,0);
        ways[0] = 1;
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            
            long long dist = it.first;
            int node = it.second;
            
            for(auto &it: adj[node]){
                int v = it.first;
                int w = it.second;
                
                if(dist + w < distance[v]){
                    ways[v] = ways[node];
                    pq.push({dist + w, v});
                    distance[v] = dist + w;
                }
                else if(dist + w == distance[v]) ways[v] = (ways[v] + ways[node]) % mod;
            }
        }
        return ways[n-1] % mod;

    }
};