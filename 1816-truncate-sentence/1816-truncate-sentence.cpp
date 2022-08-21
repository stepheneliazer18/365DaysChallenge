class Solution {
public:
    string truncateSentence(string s, int k) {
        string s2="";
        for (int i=0; i<s.size(); i++) {
            if (s[i]==' ') k--;
            if (k==0) break;
            s2+=s[i];
        }
        return s2;
    }
};
