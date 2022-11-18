class DisjointSet{
public:
    vector<int> size, parent;
    DisjointSet(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }
    int findUPar(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }
    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        
        DisjointSet ds(n);
        
        map<string,int> mp;
        
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail = accounts[i][j];
                if(mp.find(mail) != mp.end()){
                    ds.unionBySize(mp[mail],i);
                }
                else mp[mail] = i;
            }
        }
        vector<string> res[n];
        
        for(auto &it: mp){
            string mail = it.first;
            int node = ds.findUPar(it.second);
            
            if(res[node].size() == 0){
                res[node].push_back(accounts[node][0]);
            }
            
            res[node].push_back(mail);
        }
        
        vector<vector<string>> ans;
        for(auto &it: res){
            if(it.size() == 0) continue;
            ans.push_back(it);
        }
        
        return ans;
    }
};