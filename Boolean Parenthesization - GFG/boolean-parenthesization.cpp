// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[205][205][2];
    int solve(string str, int i, int j, int istrue)
    {
        if(i>j)return 0;
        if(i==j)
        {
            if(istrue)return str[i]=='T';
            else return str[i]=='F';
        }
        if(dp[i][j][istrue]!=-1)
        return dp[i][j][istrue];
        
        int ans=0;
        
        for(int k=i+1;k<=j-1;k=k+2)
        {
            int leftT,leftF,rightT,rightF;
            
            if(dp[i][k-1][1]==-1)
            leftT=solve(str,i,k-1,1);
            else leftT=dp[i][k-1][1];
            
            if(dp[i][k-1][0]==-1)
            leftF=solve(str,i,k-1,0);
            else leftF=dp[i][k-1][0];
            
            if(dp[k+1][j][1]==-1)
            rightT=solve(str,k+1,j,1);
            else rightT=dp[k+1][j][1];
            
            if(dp[k+1][j][0]==-1)
            rightF=solve(str,k+1,j,0);
            else rightF=dp[k+1][j][0];
            
            if(str[k]=='^')
            {
                if(istrue)
                ans+=(leftT*rightF) + (leftF*rightT);
                else ans+=(leftT*rightT) + (leftF*rightF) ;
            }
            else if(str[k]=='&')
            {
                if(istrue)
                ans+=(leftT*rightT);
                else ans+=(leftT*rightF) + (leftF*rightT) + (leftF*rightF);
            }
            else if(str[k]=='|')
            {
                if(istrue)
                ans+=(leftT*rightF) + (leftF*rightT) + (leftT*rightT);
                else ans+=(leftF*rightF) ;
            }
            dp[i][j][istrue]=ans%1003;
        }
        return ans%1003;
    }
    int countWays(int N, string S){
        memset(dp,-1,sizeof(dp));
        return solve(S,0,N-1,1);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends