class Solution {
public:
    int countVowelSubstrings(string word) {
        unordered_map<char,int>m;
        
        int n=word.size();
        int ans=0;
        
        for(int i=0,cnt=0,j=0,pref=0;i<n;i++){
            if((word[i]=='a'||word[i]=='e'||word[i]=='i'||word[i]=='o'||word[i]=='u')) {
                if(m[word[i]]++==0) cnt++;
                while(m[word[j]]>1)
                m[word[j++]]--,pref++;
                if(cnt==5)ans+=(1+pref);
            }
            else{
               cnt=0;
               pref=0;
               m.clear();
               j=i+1;
            }
        }
        return ans;
    }
};
