class Solution {
public:
    int countPrimes(int n){
        vector<bool> seive(n + 1, false);
        
        for(int i = 2; i < n; i++){
            if (seive[i]) continue;
            for(int j = i; j <= n / i; j++){
                seive[i*j] = true;
            }
        }

        int count = 0;
        for(int i = 2; i < n; i++){
            count += !seive[i];
        }
        
        return count;
    }

};