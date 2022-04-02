class Solution {
public:
    bool checkPalindrome(int i,int j,string s){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n = s.length();
        int i = 0;
        int j = n-1;
        
        while(i<j){
            if(s[i]!=s[j]) break;
            i++;j--;
        }
        if(checkPalindrome(i+1,j,s) || checkPalindrome(i,j-1,s)) return true;
        return false;
    }
};