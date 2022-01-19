class Solution {
public:
    string addBinary(string a, string b) {
        
        int alen = a.length()-1;
        int blen = b.length()-1;
        
        string ans;
        int carry = 0;
        while(alen>=0 || blen>=0){
            
            int a1 = (alen>=0) ? a[alen] : 48;
            int b1 = (blen>=0) ? b[blen] : 48;
            
            if(a1+b1 == 98){
                if(carry) ans+="1";
                else  ans += "0";
                carry = 1;
            }
            else if(a1+b1 == 97){
                if(carry) ans+="0";
                else ans += "1";
            }
            else{
                if(carry) ans += "1";
                else ans+= "0";
                carry = 0;
            }
            alen--; blen--;
        }
        if(carry) ans+="1";
        reverse(ans.begin(),ans.end());
        return ans;
    }
};