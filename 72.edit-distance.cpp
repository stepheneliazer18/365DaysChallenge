/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {  
        int m = word1.length();
        int n = word2.length();
        
        vector<int> dp(n+1);

        for(int i=0;i<n+1;i++) dp[i] = i;

        for(int i=1;i<m+1;i++){
            int prev = i;
            for(int j=1;j<n+1;j++){
                int cur;
                if(word1[i-1]==word2[j-1]) cur = dp[j-1];
                else cur = 1 + min(dp[j-1], min(prev,dp[j]));
                dp[j-1] = prev;
                prev = cur;
            }
            dp[n] = prev;
        }
        return dp[n];
    }
};
// @lc code=end

