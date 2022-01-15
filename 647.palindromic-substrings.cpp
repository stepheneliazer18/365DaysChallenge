/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 */

// @lc code=start
class Solution {
public:
    int countSubstrings(string str) {
        string ans;
        int max_len = 0;
        int start, end;
        int cnt = 0;
        for(int i=0;i<str.length();i++){
            int l = i, r = i;
            while(l>=0 && r<str.length() && str[l]==str[r]){
                cnt++;
                if((r-l+1) > max_len){
                    start = l;
                    max_len = r-l+1;
                }
                l--;r++;
            }
            l = i; r = i+1;
            while(l>=0 && r<str.length() && str[l]==str[r]){
                cnt++;
                if((r-l+1) > max_len){
                    start = l;
                    max_len = r-l+1;
                }
                l--;r++;
            }
        }
        return cnt;
    }
};
// @lc code=end

