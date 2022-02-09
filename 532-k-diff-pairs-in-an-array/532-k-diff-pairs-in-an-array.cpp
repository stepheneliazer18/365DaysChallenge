class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        int cnt = 0;       
        int i = 0;
        int j = i+1;
        
        while(i<j && j<n){
            int c = nums[j] - nums[i];
            if(c == k){
                cnt++;
                i++;j++;
                while(j<n && nums[j]==nums[j-1]) j++;
            }
            else if(c < k) j++;
            else i++;
            if(i==j) j++;
        }

        return cnt;
    }
};