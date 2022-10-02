class Solution {
public:
    bool areOccurrencesEqual(string s) {
        map<char,int> mp;
      
        for(auto i:s) mp[i]++;

        int comp = mp[s[0]];
        for(auto &it: mp){
            if(it.second != comp) return false;
        }
        return true;
    }
};