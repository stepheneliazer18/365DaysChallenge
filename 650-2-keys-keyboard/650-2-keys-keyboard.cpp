class Solution {
public:
    int factors(int x) {
        int ans = 1;
        for(int i=1;i<=x/2;i++){
            if(x%i==0){
                ans = i;
            }
        }
        return ans;
    }
    
    int minSteps(int n) {

        vector<int> primes;
        while(n > 1){
            primes.push_back(n);
            n = factors(n);
        }
        if(n==1) primes.push_back(1);
        
        for(auto &it: primes) cout<<it<<" ";
        cout<<endl;
        
        int ans = primes.size()-1;
        for(int i=1;i<primes.size();i++){
            ans += primes[i-1]/primes[i] - 1;
        }
        
        return ans;
    }
};