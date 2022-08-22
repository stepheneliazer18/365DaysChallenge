class Solution {
public:
    bool checkIfPangram(string sentence){
        map<char, int> mp;
        for(int i=0; i<sentence.size();i++){
            mp[sentence[i]]++;
        }
        if(mp.size() == 26){
            return true;
        }
        return false;
    }
};