class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if(n<=1) return s;
        int start = 0 , max_len = 0;
        
        for(int i=0;i<n;i++){
            int odd = expand(s,i,i);
            int even = expand(s,i,i+1);
            
            int len = max(odd,even);
            
            if(len > max_len){
                start = i - (len-1)/2;
                max_len = len;
                cout<<"start = "<<start<<endl;
                cout<<"max_len = "<<max_len<<endl;
            }
        }

        return s.substr(start,max_len);
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