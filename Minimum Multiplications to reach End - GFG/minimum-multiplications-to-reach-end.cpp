//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        int mod = 100000;
        queue<pair<int,int>> q;
        q.push({start,0});
        
        vector<int> distance(100000,INT_MAX);
        distance[start] = 0;
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int node = it.first;
            int steps = it.second;
            
            for(auto &it: arr){
                int newStart = (it*node) % mod;
                if(newStart == end) return steps + 1;
                if(steps + 1 < distance[newStart]){
                    distance[newStart] = steps + 1;
                    q.push({newStart,steps+1});
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
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends