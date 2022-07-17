class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        int n = nums.size();
        map<int,int> mp;
        
        for(auto &it: nums) mp[it]++;
        
        int pair = 0;
        for(auto &it: mp){
            pair += it.second/2;
        }
        return {pair,n-(pair*2)};
    }
};