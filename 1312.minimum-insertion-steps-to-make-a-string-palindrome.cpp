/*
 * @lc app=leetcode id=1312 lang=cpp
 *
 * [1312] Minimum Insertion Steps to Make a String Palindrome
 */

// @lc code=start
class Solution {
public:
    int minInsertions(string text1) {
        string text2 = text1;
        reverse(text2.begin(),text2.end());
        vector<vector<int>> dp(text1.length()+1,vector<int>(text2.length()+1));

        for(int i=0;i<text1.length()+1;i++) dp[i][0] = 0;
        for(int i=0;i<text2.length()+1;i++) dp[0][i] = 0;

        for(int i=1;i<text1.length()+1;i++){
            for(int j=1;j<text2.length()+1;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        return text1.length() - dp[text1.size()][text2.size()];
    }
};
// @lc code=end

