//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class DisjointSet{
private:
    vector<int> size, parent;
public:
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
private:
    bool isValid(int nx, int ny, int n, int m){
        return nx >= 0 && ny >= 0 && nx < n && ny < m;
    }
public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        DisjointSet ds(n*m);
        
        vector<int> dx{0,1,0,-1};
        vector<int> dy{1,0,-1,0};
        
        int cnt = 0;
        vector<int> res;
        
        for(auto &it: operators){
            int u = it[0];
            int v = it[1];
            
            int cellNo = m*(u) + v;
            if(vis[u][v]){
                res.push_back(cnt);
                continue;
            }
            vis[u][v] = 1;
            cnt++;
            
            for(int i=0;i<4;i++){
                int nx = u+dx[i];
                int ny = v+dy[i];
                int newCellNo = m*(nx) + ny;
                if(isValid(nx,ny,n,m) && vis[nx][ny] == 1){
                    if(ds.findUPar(cellNo) == ds.findUPar(newCellNo)) continue;
                    ds.unionBySize(cellNo, newCellNo);
                    cnt--;
                }
            }
            res.push_back(cnt);
        }
        
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends