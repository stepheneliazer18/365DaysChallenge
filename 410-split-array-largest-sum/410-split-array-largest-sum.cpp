class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int sum = 0;
        
        for(auto x: nums) sum = sum + x;
        
        int l = nums[max_element(nums.begin(), nums.end()) - nums.begin()];
        int r = sum ;
        int ans = INT_MAX;
        while(l <= r){
            
            int mid = l+(r-l)/2;
            
            int currSum = 0;
            int minSum = INT_MIN;
            int temp = 1;
            for(int i=0;i<nums.size();i++){
                if(currSum + nums[i] > mid){
                    minSum = max(minSum, currSum);
                    temp ++;
                    currSum = nums[i];
                }
                else{
                    currSum += nums[i]; 
                    minSum = max(minSum, currSum);
                }
            }
          if(temp > m) l = mid + 1;
          else {
              r = mid - 1;
              ans = min(ans, minSum);
          }
        }
        return ans;
    }
};