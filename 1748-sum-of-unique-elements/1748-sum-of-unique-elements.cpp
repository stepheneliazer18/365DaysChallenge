class Solution {
public:
    int sumOfUnique(vector<int>& n) {
        int t=0;
        vector<int> x(101,0);
        for (auto i: n){
            x[i]++;
        }
        for (int i=0;i<101;i++){
            if (x[i]==1){
                t=t+i;
            }
        }
        return t;
    }
};