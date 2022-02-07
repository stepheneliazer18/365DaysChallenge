class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        int prev = INT_MAX;
        
        for(int i=0;i<n;i++){
            if(nums[i] == prev)cnt++;
            else{
                cnt = 1;
                prev = nums[i];
            }
            if(cnt > 2) nums[i] = INT_MAX;
        }
        
        
        int i = 0;
        int j = 0;
        while(i<n && j<n){
            while(i<n && nums[i]!=INT_MAX)i++;
            while(j<n && (j<i || nums[j]==INT_MAX)) j++;
            if(i<n && j<n && nums[i] == INT_MAX && nums[j]!=INT_MAX){
                nums[i] = nums[j];
                nums[j] = INT_MAX;
                i++;j++;
            }
        }
        return i;
    }
};