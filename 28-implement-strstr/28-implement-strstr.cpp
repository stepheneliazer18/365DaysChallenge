class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();
        
        int l = 0;
        while(l+m <= n){
            string temp = haystack.substr(l,m);
            if(temp == needle) return l;
            l++;
        }
        return -1;
    }
};