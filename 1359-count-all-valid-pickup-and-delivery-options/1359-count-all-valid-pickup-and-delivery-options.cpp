class Solution {
public:
    int countOrders(int n) {
        vector<long long> dp(501);
        
        int mod = pow(10,9) + 7;
        
        dp[1] = 1L;
        dp[2] = 6L;
        
        for(int i=3;i<=n;i++){
            int cnt = 2*i - 1;
            int sum = (cnt)*(cnt+1)/2;
            dp[i] = (dp[i-1]* sum)%mod;
        }
        
        return dp[n];
    }
};