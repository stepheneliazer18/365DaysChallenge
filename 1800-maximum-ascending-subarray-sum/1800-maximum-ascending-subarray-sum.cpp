class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        int ans = INT_MIN, curr = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i - 1] < nums[i]) 
                curr += nums[i];
            else {
                ans = max(ans, curr);
                curr = nums[i];
            }
            if(i == nums.size() - 1)
                ans = max(ans, curr);
        }
        return ans;
    }
};