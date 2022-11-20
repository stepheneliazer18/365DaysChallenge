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
    int removeStones(vector<vector<int>>& stones) {
        int noOfStones = stones.size();
        int n = 0, m = 0;
        
        for(auto &it: stones){
            n = max(n,it[0]);
            m = max(m,it[1]);
        }
        n++;m++;
        
        DisjointSet ds(n+m);
        for(auto &it: stones){
            int rowNode = it[0];
            int colNode = it[1] + n;
            
            ds.unionBySize(rowNode, colNode);
        }
        
        int connectedComponents = 0;
        for(int i=0;i<n+m;i++){
            if(ds.parent[i] == i && ds.size[i] > 1) connectedComponents++;
        }
        
        return noOfStones - connectedComponents;
    }
};