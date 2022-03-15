class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        vector<int> vec;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='(')
                st.push(i);
            else if(s[i]==')'){
                if(!st.empty())
                    st.pop();
                else vec.push_back(i);
            }
        }
        while(!st.empty()){
            int x = st.top();
            vec.push_back(x);
            st.pop();
        }
        sort(vec.begin(), vec.end());
        for(int i=0; i<vec.size(); i++){
            s.erase(vec[i]-i, 1);
        }
        return s;
    }
};
