class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st;
        for(auto &it: nums) st.insert(it);
        auto it = st.begin();
        int cnt = 0;
        int i = *it;
        int maxi = 0;
        for(auto &it: st){
            if(it!=i){
                cnt = 0;
                i = it;
            }
            cnt++;i++;
            maxi = max(maxi,cnt);
        }
        return maxi;
    }
};