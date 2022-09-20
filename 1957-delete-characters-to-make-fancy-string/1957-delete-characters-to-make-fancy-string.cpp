class Solution {
public:
	string makeFancyString(string s){
        string res = "";
        int cnt = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == s[i + 1]) cnt++;
            else {
                if(cnt > 0){ 
                    res += s[i];
                    cnt = 0;
                }
                res += s[i];
            }
        }
        return res;
    }
};