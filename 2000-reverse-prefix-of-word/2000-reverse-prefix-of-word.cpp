class Solution {
public:
    string reversePrefix(string word, char ch) {
        
        int i,l=word.length();
        string s;
        for(i=0;i<l;i++)
        {
            if(word[i]==ch)
                break;
        }
        if(i==l)
            return word;
        
        s=word.substr(0,i+1);
        reverse(s.begin(),s.end());
        s+=word.substr(i+1,l-1);
        return s;
        
    }
};