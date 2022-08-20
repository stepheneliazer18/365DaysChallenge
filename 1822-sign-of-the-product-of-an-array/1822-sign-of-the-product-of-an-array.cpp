class Solution {
public:
    int arraySign(vector<int>& nums) {
        int cntN = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0) return 0;
            if(nums[i] < 0) cntN++;
        } 
        return cntN%2 == 0 ? 1 : -1;
    }
};