class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%nums.size();
        
        vector<int> vec;
        
        for(int i=n-k;i<n;i++){
            vec.push_back(nums[i]);
        }
        for(int i=0;i<n-k;i++){
            vec.push_back(nums[i]);
        }
        nums = vec;
    }
};