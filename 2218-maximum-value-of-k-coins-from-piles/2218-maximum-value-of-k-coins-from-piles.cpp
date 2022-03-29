class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<vector<int>> dp(piles.size()+1,vector<int>(k+1,0));
        for(int ind = 0;ind<piles.size();ind++){
            for(int j = 0;j<k;j++){
                int ans = dp[ind][j];
                int sum = 0;
                for(int x=0;x<min(j+1,(int)piles[ind].size());x++){
                    sum += piles[ind][x];
                    int temp = sum + dp[ind][j-x];
                    ans = max(ans,temp);
                }
                dp[ind+1][j+1] = max(ans,dp[ind][j+1]);
            }
        }
        return dp[piles.size()][k];
    }
};