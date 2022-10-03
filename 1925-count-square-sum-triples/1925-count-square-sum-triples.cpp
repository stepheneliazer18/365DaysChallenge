class Solution {
public:
    int countTriples(int n) {
        int cnt = 0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                int pow = i*i + j*j;
                int sroot = sqrt(pow);
                if(sroot*sroot == pow and sroot <= n)
                    cnt += 2;
            }
        }
        return cnt;     
    }
};