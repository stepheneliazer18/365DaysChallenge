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
        
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,s1,s2,dp);
    }
};