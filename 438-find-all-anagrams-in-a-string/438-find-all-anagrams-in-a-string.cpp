class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<int> res;
        
        map<char,int> mp;
        for(auto &it: p)mp[it]++;
        
        map<char,int> temp;
        
        int l = 0;
        int r = m-1;
        
        int cnt = 0;
        for(int i=l;i<=r;i++){
            if(mp.find(s[i])!=mp.end()){
                temp[s[i]]++;
                if(temp[s[i]] <= mp[s[i]])cnt++;
            }
        }
        if(cnt==m) res.push_back(l);
        l++;r++;
        
        while(r<n){
            if(mp.find(s[l-1])!=mp.end()){
                if(temp[s[l-1]] <= mp[s[l-1]]) cnt--;
                temp[s[l-1]]--;
            }
            if(mp.find(s[r])!=mp.end()){
                temp[s[r]]++;
                if(temp[s[r]] <= mp[s[r]])cnt++;
            }
            if(cnt==m) res.push_back(l);
            l++;r++;
        }
        
        return res;
    }
};