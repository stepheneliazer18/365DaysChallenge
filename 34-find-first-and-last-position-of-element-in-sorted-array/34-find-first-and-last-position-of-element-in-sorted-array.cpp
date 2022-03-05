class Solution {
public:
    int lower_bound(vector<int>& nums, int target){
        int l = 0;
        int r = nums.size()-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            
            if(nums[mid] < target) l = mid+1;
            else r = mid-1;
        }
        return l;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        
        int x1 = lower_bound(nums,target);
        int x2 = lower_bound(nums,target+1) - 1;
        
        if(x1<nums.size() && nums[x1]==target){
            return {x1,x2};
        }
        return {-1,-1};
    }
};