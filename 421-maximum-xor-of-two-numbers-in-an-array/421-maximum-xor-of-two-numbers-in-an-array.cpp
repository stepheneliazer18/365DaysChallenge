class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int ans = 0,mask = 0;
        for(int i=31;i>=0;i--){
            int mask = mask | 1<<i;
            unordered_set<int> st;
            for(auto &it: nums){
                st.insert(it & mask);
            }
            int temp = ans | 1<<i;
            for(auto &it: st){
                int xo = temp^it;
                if(st.find(xo)!=st.end()){
                    ans = temp;
                    break;
                }
            }
        }
        return ans;
    }
};