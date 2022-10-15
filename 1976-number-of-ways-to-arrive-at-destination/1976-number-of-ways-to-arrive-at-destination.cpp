class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        long long mod = 1000000007;
        vector<pair<long long,long long>> adj[n];
        
        for(auto &it: roads){
            long long u = it[0];
            long long v = it[1];
            long long w = it[2];
            
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> pq;
        pq.push({0,0});
        
        vector<long long> distance(n,1e18);
        distance[0] = 0;
        
        vector<long long> ways(n,0);
        ways[0] = 1;
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            
            long long dist = it.first;
            long long node = it.second;
            
            for(auto &it: adj[node]){
                long long v = it.first;
                long long w = it.second;
                
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