class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int total = n*(n+1)/2;
        for(auto &it: nums) total -= it;
        return total;
    }
};