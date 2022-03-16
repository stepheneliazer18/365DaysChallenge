class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        
        stack<int> st;
        st.push(pushed[0]);
        
        int l = 1;
        int r = 0;
        while(l<n || r<n){
            if(!st.empty() && st.top() == popped[r]){
                st.pop();
                r++;
            }
            else if(l<n){
                st.push(pushed[l]);
                l++;
            }
            else return false;
        }
        if(st.empty()) return true;
        return false;
    }
};