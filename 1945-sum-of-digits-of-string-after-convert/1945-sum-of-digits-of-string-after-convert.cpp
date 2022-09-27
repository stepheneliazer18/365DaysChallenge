class Solution {
public:
    int getLucky(string s, int k) {
        int sum=0, temp = 0;
        for (char ch: s) {
            int equivalentNum = ch - 'a' + 1;
            sum += (equivalentNum % 10) + (equivalentNum / 10);
        }
        
        for (int i=1; i<k && sum >= 10; i++) {
            temp = 0;
            while (sum) {
                temp += sum % 10;
                sum /= 10;
            }
            sum = temp;
        }
        
        return sum;
    }
};