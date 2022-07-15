class Solution {
public:
    int solve(int ind, int target, vector<int>& coins, vector<vector<int>>& dp){
        
        if(ind == 0){
            if(target % coins[0] == 0) return 1;
            return 0;
        }
        
        if(dp[ind][target] != -1) return dp[ind][target];
        
        
        int not_take = solve(ind-1,target,coins,dp);
        int take = 0;
        if(coins[ind] <= target) take = solve(ind,target-coins[ind],coins,dp);
        return dp[ind][target] = not_take + take;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return solve(n-1,amount,coins,dp);
    }
};