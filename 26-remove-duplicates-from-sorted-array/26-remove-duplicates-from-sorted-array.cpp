class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<=1) return nums.size();
        int i = 0,j = 0;

        int cnt = 1;
        while(i<=j && j<nums.size()){
            if(nums[i]==nums[j]) j++;
            else{
                i++;
                swap(nums[i],nums[j]);
                j++;
                cnt++;
            }
        }
        return cnt;
    }
};