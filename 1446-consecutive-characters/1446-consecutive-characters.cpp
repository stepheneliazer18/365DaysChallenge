class Solution {
public:
    int maxPower(string s) {
        int n = s.length();
        int ans = 0;
        
        int maxi = 1;
        int cur = 1;
        for(int i=1;i<n;i++){
            if(s[i] == s[i-1]) cur++;
            else cur = 1;
            maxi = max(cur,maxi);
        }        
        return maxi;
    }
};