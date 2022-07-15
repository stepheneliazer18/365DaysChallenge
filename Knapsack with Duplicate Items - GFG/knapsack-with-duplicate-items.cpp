// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int ind, int w, int wt[], int val[], vector<vector<int>>& dp){
        
        if(ind == 0){
            return (w/wt[0]) * val[0];
        }
        
        if(dp[ind][w] != -1) return dp[ind][w];
        
        int not_pick = solve(ind-1,w,wt,val,dp);
        int pick = INT_MIN;
        if(wt[ind] <= w) pick = val[ind] + solve(ind,w-wt[ind],wt,val,dp);
        return dp[ind][w] = max(not_pick,pick);
    }
    int knapSack(int n, int w, int val[], int wt[]){
        vector<vector<int>> dp(n, vector<int>(w+1,-1));
        return solve(n-1,w,wt,val,dp);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}  // } Driver Code Ends