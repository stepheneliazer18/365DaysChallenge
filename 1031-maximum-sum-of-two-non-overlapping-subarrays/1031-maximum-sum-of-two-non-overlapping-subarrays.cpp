class Solution {
public:
    int sumfor(int r,int len,vector<int>&nums){
        int sum = 0;
        for(int i=r;i>=r-len+1;i--) sum+=nums[i];
        return sum;
    }
    int sumback(int l,int len,vector<int>&nums){
        int sum = 0;
        for(int i=l;i<=l+len-1;i++) sum+=nums[i];
        return sum;
    }
    int help(vector<int>&nums, int firstLen, int secondLen){
        int n = nums.size();
        
        vector<int> dp11(n,0);
        int prev = 0;
        for(int i=firstLen-1;i<n;i++){
            int cur_sum = sumfor(i,firstLen,nums);
            
            dp11[i] = max(prev,cur_sum);
            prev = dp11[i];
        }
        vector<int> dp12(n,0);
        prev = 0;
        for(int i=n-secondLen;i>=0;i--){
            int cur_sum = sumback(i,secondLen,nums);
            
            dp12[i] = max(prev,cur_sum);
            prev = dp12[i];
        }
        int ans = 0;
        for(int i=0;i<n-1;i++) ans = max(ans,dp11[i]+dp12[i+1]);
        return ans;
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int x, int y) {
        
        return max(help(nums,x,y),help(nums,y,x));
    }
};