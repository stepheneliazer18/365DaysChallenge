class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> suffix(n);
        
        int prod = 1;
        for(int i=n-1;i>=0;i--){
            prod *= nums[i];
            suffix[i] = prod;
        }
        
        vector<int> ans(n);
        
        prod = 1;
        for(int i=0;i<n;i++){
            if(i == n-1){
                ans[i] = prod;
                continue;
            }
            ans[i] = prod * suffix[i+1];
            prod *= nums[i];
        }
        return ans;
    }
};