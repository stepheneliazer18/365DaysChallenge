class Solution {
public:
    int romanToInt(string s) {
        int n = s.length();
        map<char,int> mp = {{'M',1000},{'D',500},{'C',100},{'L',50},{'X',10},{'V',5},{'I',1}};
        
        int ans = 0;
        for(int i=0;i<n-1;i++){
            if(i+1<n && mp[s[i]] < mp[s[i+1]]){
                ans -= mp[s[i]];
            }
            else ans += mp[s[i]];
        }
        ans += mp[s[n-1]];
        return ans;
    }
};