class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i,j;
        for(i=n-1;i>0;i--){
            if(nums[i] > nums[i-1]){
                break;
            }
        }
        if(i>0){
            for(j=n-1;j>0;j--){
                if(nums[j] > nums[i-1]) break;
            }
            swap(nums[i-1],nums[j]);
        }
        reverse(nums.begin()+i,nums.end());
    }
};