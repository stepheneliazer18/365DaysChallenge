class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<pair<int,int>> vec;
        
        for(int i=0;i<m;i++){
            int cap = 0;
            for(auto &it: mat[i]) cap += it;
            vec.push_back({cap,i});
        }
        sort(vec.begin(),vec.end());
        
        vector<int> res;
        for(int i=0;i<k;i++){
            res.push_back(vec[i].second);
        }
        return res;
    }
};