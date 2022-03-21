class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        map<char,int> mp;
        
        for(int i=0;i<n;i++) mp[s[i]] = i;
        
        vector<int> res;
        
        int len = 0;
        int end = 0;
        for(int i=0;i<n;i++){
            
            if(mp[s[i]] > end) end = mp[s[i]]; 
            
            len++;
            
            if(end == i){
                res.push_back(len);
                len = 0;
            }
        }
        return res;
    }
};