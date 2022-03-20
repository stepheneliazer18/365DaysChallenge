class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        
        map<int,int> mpt;
        map<int,int> mpb;
        
        set<int> st;
        
        for(auto &it: tops) mpt[it]++;
        for(auto &it: bottoms) mpb[it]++;
        
        for(auto &it: mpt){
            int t = it.second;
            int b = mpb[it.first];
            if(t+b >= n) st.insert(it.first);
        }
        
        for(auto &it: mpb){
            int t = it.second;
            int b = mpt[it.first];
            if(t+b >= n) st.insert(it.first);
        }

        
        int mini = INT_MAX;
        for(auto &it: st){
            int flag = true;
            int ct = 0;
            int cb = 0;
            for(int i=0;i<n;i++){
                if(tops[i]!=it && bottoms[i]!=it){
                    flag = false;
                    break;
                }
                if(tops[i]!=it && bottoms[i]==it) ct++;
                if(tops[i]==it && bottoms[i]!=it) cb++;
                
            }
            if(flag){
                mini = min(min(cb,ct),mini);
            }
        }
        if(mini == INT_MAX) return -1;
        return mini;
    }
};