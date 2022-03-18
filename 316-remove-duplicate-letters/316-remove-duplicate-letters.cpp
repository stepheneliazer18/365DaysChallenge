class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.length();
        
        vector<bool> vec(27,false);
        map<char,int> rem;
        for(auto &it: s) rem[it]++;
        stack<char> st;
        for(int i=0;i<n;i++){
            
            rem[s[i]]--;
            if(vec[s[i] - 'a']) continue;
            
            while(!st.empty() && st.top() > s[i] && rem[st.top()] > 0){
                vec[st.top() - 'a'] = false;
                st.pop();
            }
            st.push(s[i]);
            vec[s[i] - 'a'] = true;
        }
        string res;
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};