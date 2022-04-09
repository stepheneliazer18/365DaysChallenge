bool cmp(pair<int,int> p1,pair<int,int> p2){
        return p1.second > p2.second;
}
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        
        map<int,int> mp;
        for(auto &it: nums) mp[it]++;
        for(auto &it: mp) cout<<it.first<<" "<<it.second<<endl;
        vector<pair<int,int>> vec;
        for(auto &it: mp){
            vec.push_back({it.first,it.second});
        }
        sort(vec.begin(),vec.end(),cmp);
        vector<int> res;
        for(int i=0;i<k && i<n;i++){
            res.push_back(vec[i].first);
        }
        return res;
    }
};

/*



*/