//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    bool isvalid(int x, int y, int n, int m){
        return x >= 0 && y >= 0 && x < n && y < m;
    }
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        int n = grid.size();
        int m = grid[0].size();
        
        if(source == destination) return 0;

        vector<int> dy{1,0,-1,0};
        vector<int> dx{0,1,0,-1};
        
        vector<vector<int>> distance(n,vector<int>(m,INT_MAX));
        queue<pair<int,pair<int,int>>> q;

        q.push({0,source});
        distance[source.first][source.second] = 0;
        
        while(!q.empty()){
            auto node = q.front();
            int dist = node.first;
            int x = node.second.first;
            int y = node.second.second;
            q.pop();
            
            for(int i=0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(isvalid(nx,ny,n,m) && grid[nx][ny] && dist + 1 < distance[nx][ny]){
                    if(nx == destination.first && ny == destination.second) return dist + 1;
                    q.push({dist+1,{nx,ny}});
                    distance[nx][ny] = dist+1;
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends