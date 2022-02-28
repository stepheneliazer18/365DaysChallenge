class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        
        vector<string> res;
        string str = "";
        
        for(int i=0;i<n;i++){
            if(i==n-1 || nums[i]+1 != nums[i+1]){
                if(str != "") str += "->" + to_string(nums[i]);
                else str = to_string(nums[i]);
                res.push_back(str);
                str = "";
            }
            else if(str == ""){
                str += to_string(nums[i]);
            }
        }
        return res;
    }
};