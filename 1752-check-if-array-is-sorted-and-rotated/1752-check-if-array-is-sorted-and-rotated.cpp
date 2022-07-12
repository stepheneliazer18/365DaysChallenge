class Solution {
public:
    bool check(vector<int>& nums) {
		int s=0;
        for(int i=1; i<nums.size(); i++)
            if(nums[i-1] > nums[i]) s++;
			
        if(nums[nums.size()-1] > nums[0]) s++;
        
		return s<=1;
    }
};