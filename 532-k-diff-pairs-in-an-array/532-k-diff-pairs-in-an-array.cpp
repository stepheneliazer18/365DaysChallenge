class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        
        unordered_map<int,int> mp;
        for(auto &it: nums) mp[it]++;
        
        int cnt = 0;
        for(auto &it: mp){
            if((k && mp.find(it.first+k) != mp.end()) || (!k && mp[it.first] > 1))cnt++;
        }     
              
        return cnt;
    }
};