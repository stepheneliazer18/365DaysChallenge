//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
    bool isValid(int x, int y, int n, int m){
        return x >= 0 && y >= 0 && x < n && y < m;
    }
public:
    int MinimumEffort(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        vector<int> dx{0,1,0,-1};
        vector<int> dy{1,0,-1,0};
        
        vector<vector<int>> effort(n,vector<int>(m,INT_MAX));
        effort[0][0] = 0;
        
        priority_queue<pair<int,pair<int,int>>, 
        vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        
        while(!pq.empty()){
            auto node = pq.top();
            pq.pop();
            int curEffort = node.first;
            int row = node.second.first;
            int col = node.second.second;
            
            if(row == n-1 && col == m-1) return curEffort;
            
            for(int i=0;i<4;i++){
                int newRow = row + dx[i];
                int newCol = col + dy[i];
                
                if(isValid(newRow, newCol, n, m)){
                    int nextEffort = abs(heights[newRow][newCol] - heights[row][col]);
                    int newEffort = max(curEffort, nextEffort);
                    
                    if(newEffort < effort[newRow][newCol]){
                        effort[newRow][newCol] = newEffort;
                        pq.push({newEffort,{newRow,newCol}});
                    }
                }
            }
        }
        
        return 0;
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