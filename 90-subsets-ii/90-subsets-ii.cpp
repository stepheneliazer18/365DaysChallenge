class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> res;
        for(int i=0;i<pow(2,nums.size());i++){
            vector<int> temp;
            for(int j=0;j<nums.size();j++){
                if((i & 1<<j)!=0){
                    temp.push_back(nums[j]);
                }
            }
            sort(temp.begin(),temp.end());
            res.insert(temp);
        }
        vector<vector<int>> ans;
        for(auto &it: res){
            ans.push_back(it);
        }
        return ans;
    }
};