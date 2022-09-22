class Solution {
public:
    int func(int ind, int n, int Xor, vector<int>& nums) {

        if(ind == n) return Xor;

        return func(ind+1, n, Xor ^ nums[ind], nums) + func(ind+1, n, Xor, nums);
    }

    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        return func(0, n, 0, nums);
    }
};