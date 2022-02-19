class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        
        set<int>st;
        for(auto &it : nums){
            if(it%2 ==1) st.insert(2*it);
            else st.insert(it);
        }
        
        int dif = INT_MAX;
        while(true){
            int maxi = *(--(st.end()));
            int mini = *(st.begin());

            dif = min(dif,maxi-mini);

            if(maxi %2 == 0){
                st.erase(maxi);
                st.insert(maxi/2);
            }
            else return dif;
        }
    }
};
