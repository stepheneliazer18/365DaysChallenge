// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
    public:    
    int maximizeTheCuts(int n, int a, int b, int c){
        if(n == 0) return 0;
        vector<int> dp(n+1,1);
        dp[0] = 0;
        for(int i=1;i<=n;i++){
            int ans = -1;
            if(i-a > -1) ans = max(ans,dp[i-a]);
            if(i-b > -1) ans = max(ans,dp[i-b]);
            if(i-c > -1) ans = max(ans,dp[i-c]);
            if(ans!=-1) dp[i] = ans + 1;
            else dp[i] = -1;
        }
        if(dp[n] == -1) return 0;
        return dp[n];
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends