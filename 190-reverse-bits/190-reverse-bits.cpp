class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        vector<int> vec;
        for(int i=0;i<32;i++){
            vec.push_back(n & 1);
            n = n>>1;
        }
        for(auto &it: vec) cout<<it<<" "; cout<<endl;
        uint32_t ans = 0;
        reverse(vec.begin(),vec.end());
        for(int i=0;i<vec.size();i++){
            ans += vec[i] * pow(2,i);
        }
        return ans;
    }
};