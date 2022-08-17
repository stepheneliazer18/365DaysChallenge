class Solution {
public:
    vector<string> split(string s){
        int i = 0;
        int n = s.length();
        
        vector<string> ans;
        
        string temp;
        for(int i=0;i<n;i++){
            if(i == n-1){
                if(isalpha(s[i])){
                    temp += s[i];
                    ans.push_back(temp);
                }
                else ans.push_back(temp);
            }
            else if(isalpha(s[i]) && s[i] != ' '){
                temp += s[i];
            }
            else{
                if(s[i] == ' ' || i+1 < n && !isalpha(s[i]) && isalpha(s[i+1])){
                    ans.push_back(temp);
                    temp = "";
                }
            }
        }
        return ans;
    }
    string mostCommonWord(string paragraph, vector<string>& banned) {
        vector<string> words = split(paragraph);
        
        map<string,int> mp;
        for(auto &it: words){
            string a = it;
            transform(a.begin(), a.end(), a.begin(), ::tolower);
            mp[a]++;
        }

        string ans;
        int maxi = 0;
        
        for(auto &it: mp){
            int count = it.second;
            string word = it.first;
            
            if(find(banned.begin(),banned.end(),word) != banned.end()) continue;
                        
            if(count > maxi){
                maxi = count;
                ans = word;
            }
        }
        return ans;
    }
};