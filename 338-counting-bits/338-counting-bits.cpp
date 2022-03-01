class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int> res{0};
        int offset = 1; 
        
        for(int ind=1;ind<=n;ind++){
            if(offset*2 == ind) offset *= 2;
            res.push_back(res[ind - offset] + 1);
        }
        
        return res;
    }
};