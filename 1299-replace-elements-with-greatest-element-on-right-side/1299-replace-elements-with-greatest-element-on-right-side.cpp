class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n=arr.size();
        vector<int> ans(n);
        int check=-1;
        for(int i=arr.size()-1;i>=0;i--){
            ans[i]=check;
            if(arr[i]>check){
                check=arr[i];
            }
        }
        return ans;
    }
};