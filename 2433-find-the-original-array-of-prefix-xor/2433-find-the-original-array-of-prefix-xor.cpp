class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> ans;
        int n = pref.size();
        
        int x = 0;
        for(int i=0;i<n;i++){
            int c = pref[i];
            int b = x ^ c;
            x ^= b;
            
            ans.push_back(b);
        }
        
        return ans;
    }
};