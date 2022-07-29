class Solution {
public:
    bool strongPasswordCheckerII(string pass) {
        int n = pass.length();
        if(n < 8) return false;
        bool l = false, u = false, d = false, s = false;
        for(int i = 0; i < n; i++){
            if(pass[i] >= 'a' && pass[i] <= 'z')
                l = true;
            else if(pass[i] >= 'A' && pass[i] <= 'Z')
                u = true;
            else if(isdigit(pass[i]))
                d = true;
            else
                s = true;
        }
        for(int i = 0; i < n-1; i++){
            if(pass[i+1] == pass[i])
                return false;
        }
        if(l && u && d && s)
            return true;
        return false;
    }
};
