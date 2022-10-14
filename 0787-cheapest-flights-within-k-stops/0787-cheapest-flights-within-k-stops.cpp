class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto &it: flights){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            
            adj[u].push_back({v,w});
        }
        
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        
        vector<int> prices(n,INT_MAX);
        prices[src] = 0;
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int amount = it.second.second;
            
            for(auto &it: adj[node]){
                int v = it.first;
                int w = it.second;
                
                if(stops <= k && amount + w < prices[v]){
                    prices[v] = amount + w;
                    q.push({stops + 1,{v,amount + w}});
                }
            }
        }
        if(prices[dst] == INT_MAX) return -1;
        return prices[dst];
    }
};