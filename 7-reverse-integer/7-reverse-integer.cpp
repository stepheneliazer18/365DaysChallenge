class Solution {
public:
    int reverse(int x) {
        int sign = 1;
        if(x < 0) sign = -1;
        x = abs(x);
        
        double ans = 0;
        while(x){
            int rem = x%10;
            ans = ans*10 + rem;
            x /= 10;
        }
        
        if(ans < -pow(2,31) || ans > pow(2,31)-1) return 0;
        return (int)ans * sign;
    }
};