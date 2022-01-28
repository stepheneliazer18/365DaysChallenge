class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if(n<2) return nums;
        sort(nums.begin(),nums.end());
        
        vector<int> dp(n,1);
        
        int maxi = 1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && 1+dp[j]>dp[i]){
                    dp[i] = 1+dp[j];
                    maxi = max(maxi,dp[i]);
                }
            }
        }
        vector<int> res;
        int prev = -1;
        for(int i = n-1;i>=0;i--){
            if(dp[i] == maxi && (prev%nums[i]==0 || prev==-1)) {
                res.push_back(nums[i]);
                prev = nums[i];
                maxi--;
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};