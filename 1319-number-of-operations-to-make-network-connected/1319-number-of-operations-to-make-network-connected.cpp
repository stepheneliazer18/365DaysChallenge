class DisjointSet{
public:
    vector<int> size, parent;
    DisjointSet(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        // why n+1? 
        // because it'll work for both 0 based and 1 based indexing
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        
        int extraEdges = 0;
        for(auto &it: connections){
            int u = it[0];
            int v = it[1];
            if(ds.findUPar(u) == ds.findUPar(v)){
                extraEdges++;
                continue;
            }
            ds.unionBySize(u,v);
        }
        
        int noOfComponents = 0;
        for(int i=0;i<n;i++){
            if(ds.parent[i] == i) noOfComponents++;
        }
        
        int edgesRequired = noOfComponents - 1;
        if(extraEdges >= edgesRequired) return noOfComponents - 1;
        return -1;
    }
};