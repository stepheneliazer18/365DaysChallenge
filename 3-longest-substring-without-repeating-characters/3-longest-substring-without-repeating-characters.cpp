class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n==0) return n;
        
        map<char,int> mp;
        
        int maxi = 0;
        
        int l = 0;
        int r = 0;
        
        while(r<n){
            if(mp.find(s[r]) != mp.end()) l = max(mp[s[r]] + 1 ,l);
            mp[s[r]] = r;
            maxi = max(maxi, r-l+1);
            r++;
        }
        return maxi;
    }
};