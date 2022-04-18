class Solution {
public:
    int dp[20];
    Solution(){
        memset(dp, -1, sizeof(dp));
    }
    int numTrees(int n){
        
        if(n <= 1) return 1;
        if(n == 2) return 2;
        
        int temp = 0;
        for(int i = 1; i <= n; i++){
            int l, r;
            
            if(dp[i - 1] != -1) l = dp[i - 1];
            else l = dp[i - 1] = numTrees(i - 1);

            if(dp[n - i] != -1) r = dp[n - i];
            else r = dp[n - i] = numTrees(n - i);
            
            temp += l * r;
        }
        return dp[n] = temp;
    }
};