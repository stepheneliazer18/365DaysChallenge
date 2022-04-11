class Solution {
public:
    int findSubstringInWraproundString(string p) {
       int n = p.length();
        
        map<char,int> mp;
        mp[p[0]] = 1;
        int len = 1;
        for(int i=1;i<n;i++){
            if(p[i] == p[i-1]+1 || p[i]=='a' && p[i-1]=='z'){
                len++;
            }
            else len = 1;
            
            mp[p[i]] = max(mp[p[i]],len);
        }
        int sum = 0;
        for(auto &it: mp) sum += it.second;
        return sum;
    }
};