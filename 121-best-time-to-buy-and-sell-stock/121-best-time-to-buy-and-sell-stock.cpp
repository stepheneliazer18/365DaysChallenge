class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==0)return 0;

        int mini = prices[0];
        int maxi = 0;
        for(int i=1;i<n;i++){
            mini = min(prices[i],mini);
            maxi = max(maxi,prices[i]-mini);
            
        }
        return maxi;
    }
};