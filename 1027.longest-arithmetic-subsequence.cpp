/*
 * @lc app=leetcode id=1027 lang=cpp
 *
 * [1027] Longest Arithmetic Subsequence
 */

// @lc code=start
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if(n<=2) return n;

        vector<unordered_map<int,int>> dp(n);
        int maxi = 2;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int diff = nums[j] - nums[i];
                if(dp[i].find(diff)!=dp[i].end()){
                    dp[j][diff] = dp[i][diff]+1;
                }
                else dp[j][diff] = 2;
                maxi = max(maxi,dp[j][diff]);
            }
        }
        
        for(auto &it: dp){
            for(auto &it1: it){
                cout<<it1.first<<" "<<it1.second<<endl;
            }
            cout<<"-----------"<<endl;
        }
        return maxi;
    }
};
// @lc code=end

