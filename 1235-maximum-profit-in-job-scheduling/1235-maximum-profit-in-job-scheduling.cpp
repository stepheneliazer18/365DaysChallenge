class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size();
        
        vector<vector<int>> vec;
        for(int i=0;i<n;i++) vec.push_back({endTime[i],startTime[i],profit[i]});
        sort(vec.begin(),vec.end());
        
        vector<int> dp(n);
        int res = 0;
        
        for(int i=0;i<n;i++){
            
            dp[i] = vec[i][2];
            
            if(i==0){
                res = max(res,dp[i]);
                continue;
            }
            
            dp[i] = max(dp[i],dp[i-1]);
            int cur = vec[i][1];
            for(int j=i-1;j>=0;j--){
                if(vec[j][0]<=cur){
                    dp[i] = max(dp[i],dp[j]+vec[i][2]);
                    break;
                }  
            }
            res = max(res,dp[i]);
        }
        return res;
    }
};