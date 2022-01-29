class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        int sum = 0;
        for(int i=0;i<n/2;i++){
            sum+=nums[n-1-i] - nums[i];
        }
        
        return sum;
    }
};