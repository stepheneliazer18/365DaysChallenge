class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        
        sort(nums.begin(),nums.end());
        
        int i = 0;
        int low = i+1;
        int high = n-1;
        int prev;
        
        vector<vector<int>> res;
        
        while(i<n){
            int c = -(nums[i]);
            int low = i+1;
            int high = n-1;
            while(low<high){
                if(nums[low]+nums[high]==c){
                    vector<int> temp {nums[i],nums[low],nums[high]};
                    res.push_back(temp);
                    low++;high--;
                    while(low<n && nums[low]==nums[low-1])low++;
                    while(high>=0 && nums[high]==nums[high+1])high--;
                }
                else if(nums[low]+nums[high] < c)low++;
                else high--;
            }
            i++;
            while(i<n && nums[i]==nums[i-1]) i++;
        }
        return res;
    }
};