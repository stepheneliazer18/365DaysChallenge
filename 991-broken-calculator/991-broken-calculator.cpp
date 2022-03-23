class Solution {
public:
    int brokenCalc(int s, int t) {
        
        int cnt = 0;
        while(t > s){
            if(t%2==1){
                cnt ++;
                t++;
            }
            t /= 2;
            cnt++;
        }
        
        return cnt + (s-t);
    }
};