class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();
        if(m>n) return false;
        
        map<char,int> mp;
        for(auto &it: s1) mp[it]++;
        
        map<char,int> temp;
        
        int cnt = 0;
        for(int i=0;i<m;i++){
            if(mp.find(s2[i]) != mp.end()){
                temp[s2[i]]++;
                if(temp[s2[i]]<=mp[s2[i]]) cnt++;
            }
        }
        cout<<"cnt = "<<cnt<<endl;
        if(cnt == m) return true;
        
        int l = 1;
        int r = m;
        while(r<n){
            if(mp.find(s2[l-1]) != mp.end()){
                if(temp[s2[l-1]]<=mp[s2[l-1]]) cnt--;
                temp[s2[l-1]]--;
            }
            if(mp.find(s2[r]) != mp.end()){
                temp[s2[r]]++;
                if(temp[s2[r]]<=mp[s2[r]]) cnt++;
            }
            if(cnt == m)return true;
            l++;r++;
        }
        return false;
    }
};