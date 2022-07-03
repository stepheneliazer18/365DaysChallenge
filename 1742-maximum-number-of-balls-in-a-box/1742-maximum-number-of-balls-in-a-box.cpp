class Solution {
public:
    int sumOfDigits(int x) {
        int ans = 0;
        while(x != 0) {
            ans += (x % 10);
            x /= 10;
        }
        return ans;
    }
    int countBalls(int lowLimit, int highLimit) {
        map<int, int> res;
        for(int i = lowLimit; i <= highLimit; i++) {
            res[sumOfDigits(i)]++;
        }
        int mx = INT_MIN;
        for(auto &it : res) {
            mx = max(mx, it.second);
        }
        return mx;
    }
};
