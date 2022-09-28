class Solution {
public:
    int canBeTypedWords(string text, string bl) {
        int len = text.length();
        int count = 0;
        int i = 0; 
        bool t = false;
        unordered_set<char>mp;
        for(auto &it: bl) mp.insert(it);

        while(i<=text.size()){
            if(mp.count(text[i])) t=true;
            else  if(text[i]==' '||text[i]=='\0'){
                if(!t) count++;
                t=false;
            }
            i++;
        }

        return count;
    }
};