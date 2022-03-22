class Solution {
public:
    string getSmallestString(int n, int k) {
        
        int x = n;
        
        string res;
        while(x){
            res += 'a';
            x--;
        }
        k -= n;
        
        for(int i=n-1;i>=0;i--){
            if(k > 0){
                if(k-25 > 0){
                    k-= 25;
                    res[i] = 'z';
                }
                else{
                    int j = 0;
                    for(j=0;j<26;j++){
                        if(k-j == 0) break;
                    }
                    res[i] = char(j + 'a');
                    break;
                }
            }
            else break;
        }
        return res;
    }
};