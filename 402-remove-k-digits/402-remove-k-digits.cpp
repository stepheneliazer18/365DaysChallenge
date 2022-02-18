class Solution {
public:
    string removeKdigits(string nums, int k) {
        cout<<nums<<endl;
        int n = nums.length();
        int need = n-k;
        
        stack<char> st;
        st.push(nums[0]);
        
        for(int i=1;i<n;i++){
            while(!st.empty() && nums[i] < st.top() && k>0){
                st.pop();
                k--;
            }
            if(!st.empty() || nums[i]!='0') st.push(nums[i]);
        }
        while(!st.empty() && k--) st.pop();
        if(st.empty()) return "0";

        
        while(!st.empty()){
            nums[n-1] = st.top();
            st.pop();
            n--;
        }

        return nums.substr(n);
    }
};