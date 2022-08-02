class Solution {
public:
    bool digitCount(string num) {
        map<char,int> cnt;
        int n=num.length();
        
        for(int i=0; i<n; i++){
            cnt[num[i]]++;
        }
        
        char ch;
        for(int i=0; i<n; i++){
            if(cnt[i+'0']!=num[i]-'0') return false;
                    
        }
        return true;
    }
};