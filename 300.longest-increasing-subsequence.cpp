/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        vector<int> res;
        res.push_back(nums[0]);

        for(int i=1;i<nums.size();i++){
            if(res.back()<nums[i]) res.push_back(nums[i]);
            else{
                int ind = lower_bound(res.begin(),res.end(),nums[i]) - res.begin();
                res[ind] = nums[i];
            }
        }
        return res.size();
    }
};
// @lc code=end

