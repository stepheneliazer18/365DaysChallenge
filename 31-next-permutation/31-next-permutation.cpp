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
        if(i==0){
            reverse(nums.begin(),nums.end());
            return;
        }
        i--;
        for(j=n-1;j>0;j--){
            if(nums[j] > nums[i]) break;
        }
        swap(nums[i],nums[j]);
        sort(nums.begin()+i+1,nums.end());
    }
};