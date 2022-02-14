class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n==0) return n;
        
        set<char> st;
        
        int maxi = 0;
        
        int l = 0;
        int r = 0;
        
        while(r<n){
            
            if(st.find(s[r]) == st.end()){
                st.insert(s[r]);
                maxi = max(maxi,r - l + 1);
                r++;
            }
            else{
                st.erase(s[l]);
                l++;
            }
            
            if(l>r) r++;
        }
        return maxi;
    }
};