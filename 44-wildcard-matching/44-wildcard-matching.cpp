class Solution {
public:
    bool solve(int i, int j, string& s1, string& s2, vector<vector<int>>& dp){
        
        if(i<0){
            if(j<0) return true;
            for(int x=j;x>=0;x--){
                if(s2[x] != '*') return false;
            }
            return true;
        }
        if(j<0){
            if(i<0) return true;
            return false;
        }
        
        if(dp[i][j] != -1) return dp[i][j];        
        
        if(s1[i] == s2[j] || s2[j] == '?') return dp[i][j] = solve(i-1,j-1,s1,s2,dp);
        else if(s2[j] == '*') return dp[i][j] = solve(i,j-1,s1,s2,dp) || solve(i-1,j,s1,s2,dp);
        return dp[i][j] = false;
    }
    bool isMatch(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        
        // vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        // return solve(n-1,m-1,s1,s2,dp);
        
        vector<int> prev(m+1,0);
        vector<int> cur(m+1,0);
        
        prev[0] = true;
        for(int j=1;j<=m;j++){
            bool ans = true;
            for(int x=j;x>0;x--){
                if(s2[x-1] != '*'){
                    ans = false;
                    break;
                }
            }
            prev[j] = ans;
        }
        
        for(int i=1;i<=n;i++){
            cur[0] = false;
            for(int j=1;j<=m;j++){
                if(s1[i-1] == s2[j-1] || s2[j-1] == '?') cur[j] = prev[j-1];
                else if(s2[j-1] == '*') cur[j] = cur[j-1] || prev[j];
                else cur[j] = false;
            }
            prev = cur;
        }
        return prev[m];
    }
};