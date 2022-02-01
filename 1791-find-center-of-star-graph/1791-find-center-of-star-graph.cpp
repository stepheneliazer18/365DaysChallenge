bool cmp(pair<int,int> &p1, pair<int,int> &p2){
    return p1.second > p2.second;
}
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int,int> mp;
        for(auto &it: edges){
            mp[it[0]]++;
            mp[it[1]]++;
        }
        vector<pair<int,int>> vec;
        for(auto &it: mp)vec.push_back(it);
        sort(vec.begin(),vec.end(),cmp);
        return vec.begin()->first;
    }
};