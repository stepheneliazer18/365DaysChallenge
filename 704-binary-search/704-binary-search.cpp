class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n-1;
        
        while(l<=r){
            int mid = (r+l)/2;
            
            if(nums[mid] == target) return mid;
            
            if(target < nums[mid]) r = mid-1;
            else l = mid+1;
        }
        // if(nums[l] == target) return l;
        return -1;
    }
};