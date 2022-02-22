class Solution {
public:
    int titleToNumber(string s) {
        int n = s.length();
        
        int res = 0;
        int x = 0;
        for(int i=n-1;i>=0;i--){
            res += (s[i] - 'A' + 1) * pow(26,x);
            x++;
        }
        return res;
    }
};