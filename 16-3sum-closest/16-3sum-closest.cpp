class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        
        int ans = INT_MAX;
        int min_diff = INT_MAX;
                
        int i = 0;
        while(i<n){
            int j=i+1;
            int k=n-1;
            int need = target - nums[i];
            
            while(j<k){                
                int sum = nums[i] + nums[j] + nums[k];
                int diff = abs(target - sum);
                if(diff < min_diff){
                    min_diff = diff;
                    ans = sum;
                }
                
                sum = nums[j] + nums[k];
                
                if(sum < need) j++;
                else k--;
            }
            i++;
        }
        return ans;
    }
};