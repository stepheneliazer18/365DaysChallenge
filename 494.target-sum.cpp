/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */

// @lc code=start
class Solution {
public:
    int solve(vector<int>& nums, int sum){
        int n = nums.size();
        int res[n+1][sum+1];
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(!i)res[i][j]=0;
                if(!j)res[i][j]=1;
            }
        }

        for(int i=1;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(nums[i-1]<=j)res[i][j] = res[i-1][j-nums[i-1]] + res[i-1][j];
                else res[i][j] = res[i-1][j];
            }
        }
        
        return res[n][sum];
    }
    int findTargetSumWays(vector<int>& nums, int target) {

        int SumOfVec = 0;
        for(int &it: nums)SumOfVec+=it;
        if(abs(target) > SumOfVec || (SumOfVec-target)%2 != 0) return 0;


        int sum = (target+SumOfVec)/2;

        return solve(nums,sum);
    }
};
// @lc code=end

