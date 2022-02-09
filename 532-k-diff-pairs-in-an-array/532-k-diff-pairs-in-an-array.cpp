class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(auto &it: nums) cout<<it<<" ";cout<<endl;
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
        
        
        int i = 0;
        int j = i+1;
        
        while(i<j && j<n){
            cout<<i<<" "<<j<<endl;
            int c = nums[j] - nums[i];
            if(c == k){
                cnt++;
                i++;j++;
                while(i<j && nums[i]==nums[i-1]) i++;
                while(j<n && nums[j]==nums[j-1]) j++;
            }
            else if(c < k) j++;
            else if(j == i+1){
                j++;i++;
            }
            else i++;
        }
        cout<<" -------- "<<endl;
        return cnt;
    }
};