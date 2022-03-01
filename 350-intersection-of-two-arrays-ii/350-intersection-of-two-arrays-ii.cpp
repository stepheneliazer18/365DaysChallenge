class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int, int> mp;
        for(auto i: nums1) mp[i]++;
        for(auto &it: nums2)
            if(mp.count(it)){
                res.push_back(it);
                mp[it]--;
                if(mp[it]==0) mp.erase(it);
            }
        return res;
    }
};