class Solution {
public:
    string makeGood(string s) {
        vector<char> st ;
        for(int i = 0 ; i < s.size() ; ++i ){
            bool removed = false ;
            if(st.size() and abs(st.back() - s[i]) == 32) removed = true , st.pop_back() ;
            if(!removed) st.push_back(s[i]) ;
        }
        
        return string(begin(st),end(st)) ;
    }
};