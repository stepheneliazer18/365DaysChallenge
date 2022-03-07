class Solution {
public:
    
    vector<string> nums{"0","0","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    
    vector<string> help(string digits, int i){
        if(i==digits.size()) return {};
        if(i == digits.size()-1){
            vector<string> res;
            for(auto &it: nums[digits[i] - '0']){
                char x = it;
                string str;
                str += x;
                res.push_back(str);
            }
            return res;
        }
        
        cout<<digits[i]<<endl;
        
        vector<string> temp = help(digits,i+1);
        for(auto &it: temp) cout<<it<<" ";cout<<endl;
        
        vector<string> ans;
        for(auto &i: nums[digits[i] - '0']){
            for(auto &j: temp){
                ans.push_back(i+j);
            }
        }
        return ans;
    }
    
    vector<string> letterCombinations(string digits) {
        return help(digits,0);
    }
};