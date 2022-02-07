class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char,int> mp;
        
        for(auto &it: s)mp[it]++;
        
        for(auto &it: t){
            if(mp[it] ==0 || mp.find(it) == mp.end()){
                return it;
            }
            mp[it]--;
        }
        return 'd';
    }
};