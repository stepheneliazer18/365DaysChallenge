class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        
        unordered_map<int,int> mp;
        for(auto &it: nums) mp[it]++;
        
        int cnt = 0;
        for(auto &it: mp){
            if(mp.find(it.first+k) != mp.end()){
                if(k==0){
                    if(mp[it.first] > 1) cnt++;
                }
                else cnt++;
            }
        }     
              
        return cnt;
    }
};