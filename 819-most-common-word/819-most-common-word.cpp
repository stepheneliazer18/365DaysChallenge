class Solution {
public:
    vector<string> split(string s){
        int n = s.length();
        
        vector<string> ans;
        string word;
        
        for(int i=0;i<n;i++){
            if(s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z') word += s[i];
            else if(word != ""){
                ans.push_back(word);
                word = "";
            }
        }
        if(word != "") ans.push_back(word);
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