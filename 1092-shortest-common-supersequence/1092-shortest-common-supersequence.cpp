class Solution {
public:
    string shortestCommonSupersequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
                        
        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=m;ind2++){
                if(text1[ind1-1] == text2[ind2-1]) dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
                else{
                    int left = dp[ind1-1][ind2];
                    int right = dp[ind1][ind2-1];
                    dp[ind1][ind2] = max(left,right);
                }
            }
        }
        string res;
        int i = n, j = m;
        while(i > 0 && j > 0){
            if(text1[i-1] == text2[j-1]){
                res += text1[i-1];
                i--;j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                res += text1[i-1];
                i--;
            }
            else{
                res += text2[j-1];
                j--;
            }
        }
        while(i > 0) res += text1[--i];
        while(j > 0) res += text2[--j];
        
        reverse(res.begin(),res.end());
        return res;
    }
};