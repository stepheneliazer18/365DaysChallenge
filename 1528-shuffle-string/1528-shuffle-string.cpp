class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string se = s;
        for(int i = 0;i<s.size();i++){
            se[indices[i]]=s[i];
        }
        return se;
    }
};