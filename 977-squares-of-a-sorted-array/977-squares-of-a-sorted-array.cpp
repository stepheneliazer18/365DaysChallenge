class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        
        int left = 0;
        int right = nums.size()-1;
        
        while(left<=right){
            int left_val = nums[left] * nums[left];
            int right_val = nums[right] * nums[right];
            
            if(left_val>right_val) {
                ans.push_back(left_val);
                left++;
            }
            else{
                ans.push_back(right_val);
                right--;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};