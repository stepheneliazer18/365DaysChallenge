class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.length();
        
        int i;
        for(i=0;i+k<n;i+=(2*k)){
            reverse(s.begin()+i,s.begin()+i+k);
        }
        if(i!=n) reverse(s.begin()+i,s.end());
        return s;
    }
};