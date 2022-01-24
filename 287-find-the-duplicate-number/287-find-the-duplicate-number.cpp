class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int n = nums.size();

        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            if(mp[nums[i]]>=2)return nums[i];
        }
        
        return 0;
    }
};