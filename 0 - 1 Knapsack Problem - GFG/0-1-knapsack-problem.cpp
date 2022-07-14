// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    
    
    
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int solve(int ind, int w, int wt[], int val[], vector<vector<int>> dp){
        if(ind == 0){
            if(wt[ind] <= w) return val[0];
            return 0;
        }
        
        if(dp[ind][w] != -1) return dp[ind][w];
        
        int not_take = solve(ind-1,w,wt,val,dp);
        int take = INT_MIN;
        if(wt[ind] <= w) take = val[ind] + solve(ind-1,w-wt[ind],wt,val,dp);
        return dp[ind][w] = max(not_take,take);
    }
    int knapSack(int W, int wt[], int val[], int n){ 
        vector<vector<int>> dp(n,vector<int>(W+1,-1));
        // return solve(n-1,W,wt,val,dp);
        
        for(int i=0;i<=W;i++){
            if(wt[0] <= i) dp[0][i] = val[0];
            else dp[0][i] = 0;
        }
        
        for(int ind=1;ind<n;ind++){
            for(int w = 0;w<=W;w++){
                int not_take = dp[ind-1][w];
                int take = INT_MIN;
                if(wt[ind] <= w) take = val[ind] + dp[ind-1][w-wt[ind]];
                dp[ind][w] = max(take,not_take);
            }
        }
        return dp[n-1][W];
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends