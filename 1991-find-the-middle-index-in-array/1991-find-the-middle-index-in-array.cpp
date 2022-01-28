class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        
        for(int i=0;i<n;i++){
            int lsum = 0;
            int rsum = 0;
            int l = i-1;
            int r = i+1;
            
            while(l>=0){
                lsum+= nums[l];
                l--;
            }
            while(r<n){
                rsum += nums[r];
                r++;
            }
            if(lsum == rsum) return i;
        }
        return -1;
    }
};