class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        
        int l=0;
        int r = n-1;
        for(l=0;l<n-1;l++)  if(nums[l] > nums[l+1])break; 
        for(r=n-1;r>0;r--) if(nums[r] < nums[r-1])break; 
        
        if(r==0) return 0;  //This condition executes if array is sorted
        
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i=l;i<=r;i++){
            mini = min(mini, nums[i]);
            maxi = max(maxi, nums[i]);
        }
        
        for(l=0;l<n;l++) if(mini < nums[l]) break;
        for(r = n-1;r>=0;r--) if(maxi > nums[r]) break;

        return r-l+1;
    }
};