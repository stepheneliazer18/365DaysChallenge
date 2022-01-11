/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 */

// @lc code=start
class Solution {
public:   
    int dp[1001][1001];
    int helper(string &text1,string &text2,int text1_len, int text2_len){
        if(text1_len+1 == 0 or text2_len+1 == 0) return 0;
        if(dp[text1_len][text2_len] != -1) return dp[text1_len][text2_len];
        if(text1[text1_len] == text2[text2_len])
            return dp[text1_len][text2_len] = 1 + helper(text1,text2,text1_len-1,text2_len-1);
        else
            return dp[text1_len][text2_len] = max(helper(text1,text2,text1_len,text2_len-1),helper(text1,text2,text1_len-1,text2_len));
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
        return helper(text1,text2,text1.length()-1,text2.length()-1);
    }
};
// @lc code=end

