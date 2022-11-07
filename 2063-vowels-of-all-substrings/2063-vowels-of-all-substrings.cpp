class Solution {
public:
    long long countVowels(string word) {
        long long ans = 0;
        long long n = word.size();
        
        set<char> c = {'a','e','i','o','u'};
        
        for(long long i=0; i<n; i++){
            if(c.find(word[i]) != c.end()){
                ans += (i+1)*(n-i);
            }
        }
        
        return ans;
    }
};