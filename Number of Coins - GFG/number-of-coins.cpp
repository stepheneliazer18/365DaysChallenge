// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int minCoins(int coins[], int M, int amount) 
	{ 
	    int n = M;
        int m = amount;

        vector<vector<int>> res(n+1,vector<int>(m+1));

        for(int i=0;i<=m;i++){
            res[0][i] = 10001;
        }
        for(int i=0;i<=n;i++){
            res[i][0] = 0;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(coins[i-1]<=j) res[i][j] = min(res[i-1][j],res[i][j-coins[i-1]]+1);
                else res[i][j] = res[i-1][j];
            }
        }

        if(res[n][m]>10000) return -1;
        return res[n][m];
	} 
	  
};

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends