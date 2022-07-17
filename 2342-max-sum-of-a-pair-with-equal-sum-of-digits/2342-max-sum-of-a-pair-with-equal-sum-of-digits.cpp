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
        vector<pair<int,int>> vec;
        for(int i=0;i<n;i++){
            vec.push_back({digitSum(nums[i]),nums[i]});
        }
        sort(vec.begin(),vec.end());
        
        int ans = -1;
        int i = 1;
        while(i<n){
            while(i<n && vec[i].first == vec[i-1].first){
                ans = max(ans,vec[i].second + vec[i-1].second);
                i++;
            }
            i++;
        }
        return ans;
    }
};