class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.size();
        for(int i=1;i<n;i++){
            if(n%i==0){
                string curr=s.substr(0,i);
                bool flag=true;
                for(int j=i;j<n;j=j+curr.size()){
                    if(curr!=s.substr(j,i)){
                        flag=false;
                        break;
                    }
                }
                if(flag){
                    return true;
                }
            }
        }
        return false;
    }
};