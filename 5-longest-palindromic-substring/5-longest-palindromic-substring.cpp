class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if(n<=1) return s;
        int start =0 , end =0;
        
        for(int i=0;i<n;i++){
            int odd = expand(s,i,i);
            int even = expand(s,i,i+1);
            
            int len = max(odd,even);
            
            if(len > end-start){
                start = i - (len-1)/2;
                end = i + len/2;
            }
        }

        return s.substr(start,end-start+1);
    }
    
    //helper fucntion
    int expand(string s , int left , int right){
        while(left>=0 && right<s.length() && s[left]==s[right]){
            left--;
            right++;
        }
        
        return right-left-1;
    }
};