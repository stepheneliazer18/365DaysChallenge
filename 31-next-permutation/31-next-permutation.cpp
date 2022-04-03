class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        
        int i;
        for(i=n-2;i>=0;i--){
            if(nums[i] < nums[i+1]) break;
        }
        int x = i;
        if(i!=-1){
            for(i=n-1;i>=0;i--){
                if(nums[i] > nums[x]) break;
            }
            swap(nums[i],nums[x]);
        }
        sort(nums.begin()+x+1,nums.end());

    }
};

/*

*/