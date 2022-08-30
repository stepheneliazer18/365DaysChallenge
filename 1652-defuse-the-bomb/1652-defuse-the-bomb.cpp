class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> res;
        int n = code.size();
        for(int i = 0; i < n; i++){
            int m = k, sum = 0, j = i;
            if(m == 0) sum = 0;
            else if(m > 0){
                while(m--){
                    if(++j == n) j = 0;
                    sum += code[j];
                }
            } else {
                m = -m;
                while(m--){
                    if(--j < 0) j = n - 1;
                    sum += code[j];
                }
            }
            res.push_back(sum);
        }
        return res;
    }
};