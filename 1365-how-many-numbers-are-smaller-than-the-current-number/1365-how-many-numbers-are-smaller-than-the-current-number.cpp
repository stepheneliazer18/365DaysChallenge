class Solution {
public:
     vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> dup = nums;
        sort(nums.begin(), nums.end());
        unordered_map<int , int>m;
        for(int i = nums.size() - 1; i >= 0; i--) m[nums[i]] = i;

        for(int i = 0; i < nums.size(); i++) nums[i] = m[dup[i]];
        return nums;
    }
};