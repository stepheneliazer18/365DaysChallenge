class Solution {
public:
    vector<vector<int>> res;
    void help(vector<int>& nums,int i){
        if(i == nums.size()){
            res.push_back(nums);
            return;
        }

        for(int x=i;x<nums.size();x++){
            swap(nums[x], nums[i]);
            help(nums,i+1);
            swap(nums[x], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        help(nums,0);
        return res;
    }
};