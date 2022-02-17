class Solution {
public:
    vector<vector<int>> res;
    void help(vector<int>& cand, int ind, vector<int>& vec, int target){
        if(target < 0) return;
        if(target == 0){
            res.push_back(vec);
            return;
        }
        if(ind == cand.size()) return;
        
        help(cand,ind+1,vec,target);
        vec.push_back(cand[ind]);
        help(cand,ind,vec,target-cand[ind]);
        vec.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& cand, int target) {
        vector<int> vec;
        help(cand,0,vec,target);
        
        return res;
    }
};