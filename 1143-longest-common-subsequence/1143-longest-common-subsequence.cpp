class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        vector<int> dp(text2.length()+1);

        for(int i=0;i<text2.length()+1;i++) dp[i] = 0;

        for(int i=1;i<text1.length()+1;i++){
            int prev = 0;
            for(int j=1;j<text2.length()+1;j++){
                int cur;
                if(text1[i-1]==text2[j-1]) cur = dp[j-1]+1;
                else cur = max(dp[j],prev);
                dp[j-1] = prev;
                prev = cur;
            }
            dp[text2.length()] = prev;
        }

        return dp[text2.length()];
    }
};