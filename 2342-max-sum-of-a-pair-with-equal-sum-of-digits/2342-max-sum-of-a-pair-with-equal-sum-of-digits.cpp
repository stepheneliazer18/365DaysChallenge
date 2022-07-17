class Solution {
public:
    int digitSum(int n){
        int ans = 0;
        while(n){
            int rem = n%10;
            ans += rem;
            n/=10;
        }
        return ans;
    }
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        map<int,int> mp;
        
        int ans = -1;
        for(auto &it: nums){
            int dig = digitSum(it);
            if(mp.find(dig) != mp.end()){
                ans = max(ans,mp[dig]+it);
                mp[dig] = max(mp[dig],it);
            }
            else{
                mp[dig] = it;
            }
        }
        return ans;
    }
};