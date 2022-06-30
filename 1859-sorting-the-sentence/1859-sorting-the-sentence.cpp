class Solution {
public:
    string sortSentence(string s) {
        int n = s.length();
        map<char,string> mp;
        
        string temp;
        for(int i=0;i<n;i++){
            if(s[i] == ' '){
                mp[temp[temp.length()-1]] = temp.substr(0,temp.length()-1);
                temp = "";
            }
            else if(i == n-1){
                temp += s[i];
                mp[temp[temp.length()-1]] = temp.substr(0,temp.length()-1);
                temp = "";
            }
            else{
                temp += s[i];
            }
        }
        
        string res;
        for(auto &it: mp) res +=  it.second + ' ';
        
        return res.substr(0,res.length()-1);
    }
};