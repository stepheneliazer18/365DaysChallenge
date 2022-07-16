class Solution {
public:
    int solve(int ind1, int ind2, string s1, string s2, vector<vector<int>>& dp){
        
        if(ind1 < 0 || ind2 < 0) return 0;
        
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        
        if(s1[ind1] == s2[ind2]){
            return 1 + solve(ind1-1, ind2-1,s1,s2,dp);
        }
        
        int left = solve(ind1-1,ind2,s1,s2,dp);
        int right = solve(ind1,ind2-1,s1,s2,dp);
        
        return dp[ind1][ind2] = max(left,right);
    }

    int minInsertions(string s1) {
        int n = s1.length();
        string s2 = s1;
        reverse(s2.begin(),s2.end());
        
        vector<int> prev(n+1,0);
        
        for(int ind1=1;ind1<=n;ind1++){
            vector<int> cur(n+1,0);
            for(int ind2=1;ind2<=n;ind2++){
                
                if(s1[ind1-1] == s2[ind2-1]) cur[ind2] = 1 + prev[ind2-1];
                else{
                    int left = prev[ind2];
                    int right = cur[ind2-1];
                    cur[ind2] = max(left,right);
                }
            }
            prev = cur;
        }
        return n - prev[n];
    }
};