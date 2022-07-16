class Solution {
public:
    int solve(int ind1, int ind2, string &s1, string &s2, vector<vector<int>>& dp){
        if(ind2 == 0) return 1;
        if(ind1 == 0) return 0;
        
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        
        if(s1[ind1-1] == s2[ind2-1]){
            int moveBoth = solve(ind1-1,ind2-1,s1,s2,dp);
            int moveFirst = solve(ind1-1,ind2,s1,s2,dp);
            return dp[ind1][ind2] = moveBoth + moveFirst;
        }
        
        return dp[ind1][ind2] = solve(ind1-1,ind2,s1,s2,dp);
    }
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solve(n,m,s,t,dp);
    }
};