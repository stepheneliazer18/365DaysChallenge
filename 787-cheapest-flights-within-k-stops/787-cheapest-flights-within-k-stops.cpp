class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto &it: flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        vector<int> original(n);
        vector<int> temp(n);
        original[src] = 0;
        for(int i=0;i<n;i++){
            if(i!=src) original[i] = INT_MAX;
        }
        
        for(int i=0;i<k+1;i++){
            temp = original;
            
            for(auto &it: flights){
                int s = it[0];
                int d = it[1];
                int p = it[2];
                if(original[s] == INT_MAX) continue;
                if(original[s] + p < temp[d]) temp[d] = original[s] + p;
            }
            original = temp;
        }
        return original[dst] == INT_MAX ? -1 : original[dst];
    }
};