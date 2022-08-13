class Solution {
public:
    string modifyString(string s) {
        if (s[0] == '?') {
            if (s[1] == 'a')
                s[0] = 'b';
            else
                s[0] = 'a';
        }
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '?') {
                if (s[i - 1] != 'a' && s[i + 1] != 'a')
                    s[i] = 'a';
                else if (s[i - 1] != 'b' && s[i + 1] != 'b')
                    s[i] = 'b';
                else if ((s[i - 1] != 'a' && s[i + 1] != 'b') || (s[i - 1] != 'b' && s[i + 1] != 'a'))
                    s[i] = 'c';
            }
        }
        return s;
    }
};