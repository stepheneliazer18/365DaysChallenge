class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==1) return nums[0]%k==0;
        int cnt = 0;
        unordered_map<int,int> mp;
        int sum = 0;
        mp[0]=1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int rem = sum%k;
            if(rem<0) rem+=k;
            if(mp[rem]){
                cnt+=mp[rem];
                mp[rem]++;
            }
            else mp[rem]++;
        }
        return cnt;
    }
};