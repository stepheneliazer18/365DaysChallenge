class Solution
{
public:
    int findMin(vector<int> &nums){
        int n = nums.size();
        
        if(n==1) return nums[0];
        
        if (nums[0] < nums[n - 1]) return nums[0];
        
        int start = 0;
        int end = n - 1;
        while (start < end){
            
            int mid = (start+end)/2;
            
            if (nums[mid] > nums[mid + 1]) return nums[mid + 1];
            
            if(nums[start] > nums[mid]) end = mid;
            else start = mid;
        }
        return 0;
    }
};