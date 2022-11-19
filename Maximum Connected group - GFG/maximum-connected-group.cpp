//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

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
private:
    bool isValid(int nx, int ny, int n){
        return nx >= 0 && ny >= 0 && nx < n && ny < n;
    }
public:
    int MaxConnection(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        
        vector<int> dx{0,1,0,-1};
        vector<int> dy{1,0,-1,0};
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    int curCellNo = (n * i) + j;
                    for(int x=0;x<4;x++){
                        int nx = i + dx[x];
                        int ny = j + dy[x];
                        int adjCellNo = (n * nx) + ny;
                        if(isValid(nx,ny,n) && grid[nx][ny] == 1){
                            if(ds.findUPar(curCellNo) == ds.findUPar(adjCellNo)) continue;
                            ds.unionBySize(curCellNo, adjCellNo);
                        }
                    }
                }
            }
        }
        
        int maxCnt = 0;
        
        set<int> st;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int curCnt = 1;
                if(grid[i][j] == 0){
                    int curCellNo = (n * i) + j;
                    for(int x=0;x<4;x++){
                        int nx = i + dx[x];
                        int ny = j + dy[x];
                        int adjCellNo = (n * nx) + ny;
                        if(isValid(nx,ny,n) && grid[nx][ny] == 1){
                            int adjUltPar = ds.findUPar(adjCellNo);
                            if(st.find(adjUltPar) != st.end()) continue;
                            curCnt += ds.size[adjUltPar];
                            st.insert(adjUltPar);
                        }
                    }
                }
                maxCnt = max(maxCnt, curCnt);
                st.clear();
            }
        }
        
        return maxCnt;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends