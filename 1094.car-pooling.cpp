/*
 * @lc app=leetcode id=1094 lang=cpp
 *
 * [1094] Car Pooling
 */

// @lc code=start
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        int distance = 0;
        for(auto &it: trips){
            distance = max(distance,it[2]);
        }
        
        vector<int> starting(distance+1,0);
        vector<int> ending(distance+1,0);
        vector<int> dp(distance+1,0);

        for(auto &it: trips){
            starting[it[1]] = it[0];
            ending[it[2]] = it[0];
        }

        dp[1] = trips[0][0];
        for(int i=2;i<distance+1;i++){
            dp[i]=dp[i-1]+starting[i]-ending[i];
            if(dp[i]>capacity) return false;
        }
        return true;
    }
};
// @lc code=end

