class Solution {
public:
    int commonFactors(int a, int b) {
        int small = min(a,b);
        int big = max(a,b);
        int ans=0;
        for(int i=1;i<=small;i++){
            if(big%i==0 and small%i==0){
                ans++;
            }
        }
        return ans;
    }
};