class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int cnt = 0;
        if(k==0){
            for(int i=0;i<n-1;i++){
                if(nums[i]==nums[i+1]){
                    cnt++;
                    while(i<n-1 && nums[i]==nums[i+1]) i++;
                }
            }
            return cnt;
        }
        
        
        int low = 0;
        while(low<n){
            int c = nums[low] + k;
            
            int l = low+1;
            int r = n-1;
            
            int mid;
            while(l<=r){
                mid = (l+r)/2;
                if(nums[mid] == c){
                    break;
                }
                else if(c < nums[mid]) r = mid-1;
                else l = mid+1;
            }
            if(nums[mid] == c && low<n-1 && nums[low]!=nums[low+1]) cnt++;
            low++;
        }
        return cnt;
    }
};