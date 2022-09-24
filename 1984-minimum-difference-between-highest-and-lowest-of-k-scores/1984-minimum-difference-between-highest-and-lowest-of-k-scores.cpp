class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = INT_MAX;
        int i = 0;
        while(i + k - 1 < n){
            ans = min(nums[i + k - 1] - nums[i], ans);
            i++;
        }
        return ans;
    }
};