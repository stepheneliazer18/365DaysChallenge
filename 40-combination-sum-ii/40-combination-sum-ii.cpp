class Solution {
public:
    void combinations(int ind, int target, vector<int>& output, vector<int>& candidates, vector<vector<int>>& ans){
        if(ind < 0){
            if(target == 0) ans.push_back(output);
            return;
        }
        
        if(target >= candidates[ind]){
            output.push_back(candidates[ind]);
            
            combinations(ind-1,target - candidates[ind],output,candidates,ans);
            output.pop_back();
        }
        
        while(ind - 1 >= 0 && candidates[ind-1] == candidates[ind]) ind--;
        combinations(ind-1,target,output,candidates,ans);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> output;
        combinations(n-1,target,output,candidates,ans);
        return ans;
    }
};