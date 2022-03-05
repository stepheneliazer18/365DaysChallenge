class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        
        vector<int> res{-1,-1};
        if(n==0) return res;
        
        int l = 0;
        int r = n-1;
        
        int mid = 0;
        while(l<r){
            mid = (r+l)/2;
            
            if(nums[mid] == target){
                break;
            }
            if(nums[l] == target){
                mid = l;
                break;
            }
            if(nums[r] == target){
                mid = r;
                break;
            }
            if(nums[mid] < target) l = mid+1;
            else r = mid;
        }
        cout<<mid<<endl;
        if(nums[mid] == target && l<=r){
            l = mid;
            r = mid;
            
            while(nums[l]==target || nums[r]==target){
                if(l-1 >= 0 && nums[l-1] == target) l--;
                else if(r+1 < n && nums[r+1]==target) r++;
                else break;
            }
            res[0] = l;
            res[1] = r;
        }
        return res;
    }
};