class Solution {
public:
    static bool cmp(string &s1,string &s2){
        return s1+s2 > s2+s1;
    }
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        
        vector<string> vec(n);
        for(int i=0;i<n;i++) vec[i] = to_string(nums[i]);
        sort(vec.begin(),vec.end(),cmp);
        
        string ans;
        for(auto &it: vec) ans += it;
        if(ans[0]== '0') return "0";
        return ans;
    }
};