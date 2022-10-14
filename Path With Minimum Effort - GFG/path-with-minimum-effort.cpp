//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
    bool isvalid(int x, int y, int n, int m){
        return x >= 0 && y >= 0 && x < n && y < m;
    }
public:
    int MinimumEffort(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        vector<int> dx{0,1,0,-1};
        vector<int> dy{1,0,-1,0};
        
        vector<vector<int>> difference(n,vector<int>(m,INT_MAX));
        difference[0][0] = 0;
        
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        
        while(!pq.empty()){
            auto node = pq.top();
            int diff = node.first;
            int x = node.second.first;
            int y = node.second.second;
            pq.pop();
            
            if(x == n-1 && y == m-1) return diff;
            
            for(int i=0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                
                if(isvalid(nx,ny,n,m)){
                    int newEffort = max(abs(heights[x][y] - heights[nx][ny]),diff);
                    if(newEffort < difference[nx][ny]){
                        difference[nx][ny] = newEffort;
                        pq.push({newEffort,{nx,ny}});
                    }
                }
            }
        }
        
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends