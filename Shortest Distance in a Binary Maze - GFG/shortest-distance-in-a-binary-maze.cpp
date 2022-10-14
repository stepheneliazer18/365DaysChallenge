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
        if(source == destination) return 0;
        int n = grid.size();
        int m = grid[0].size();
        
        vector<int> dy{1,0,-1,0};
        vector<int> dx{0,1,0,-1};
        
        vector<vector<int>> distance(n,vector<int>(m,INT_MAX));
        // priority_queue<int, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        set<pair<int,pair<int,int>>> st;
        
        // pq.push({0,source});
        st.insert({0,source});
        distance[source.first][source.second] = 0;
        
        while(!st.empty()){
            // int dist = pq.top().first;
            // int x = pq.top().second.first;
            // int y = pq.top().second.second;
            // pq.pop();
            
            auto node = *(st.begin());
            int dist = node.first;
            int x = node.second.first;
            int y = node.second.second;
            st.erase(node);
            
            for(int i=0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(isvalid(nx,ny,n,m) && grid[nx][ny] && dist + 1 < distance[nx][ny]){
                    // pq.push({dist+1,{nx,ny}});
                    if(distance[nx][ny] != INT_MAX) st.erase({distance[nx][ny],{nx,ny}});
                    st.insert({dist+1,{nx,ny}});
                    distance[nx][ny] = dist+1;
                }
            }
        }
        int ans = distance[destination.first][destination.second];
        if(ans == INT_MAX) return -1;
        return ans;
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