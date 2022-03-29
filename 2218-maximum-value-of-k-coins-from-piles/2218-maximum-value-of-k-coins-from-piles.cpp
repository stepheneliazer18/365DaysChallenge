class Solution {
public:
    int help(int ind, int k, vector<vector<int>>& piles, vector<vector<int>>&lookup){
        if(ind == -1 || k==0) return 0;
        
        if(lookup[ind][k] != -1) return lookup[ind][k];
        int ans = help(ind-1,k,piles,lookup);
        int sum = 0;
        for(int i=0;i<min(k,(int)piles[ind].size());i++){
            sum += piles[ind][i];
            int temp = sum + help(ind-1,k-i-1,piles,lookup);
            ans = max(ans,temp);
        }
        return lookup[ind][k] = ans;
    }
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