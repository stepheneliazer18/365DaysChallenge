class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        
        set<vector<int>> st;
        
        for(int i=0;i<n;i++){
            for(int j = i+1;j<n;j++){
                if(abs(nums[i]-nums[j]) == k){
                    vector<int> temp {nums[i],nums[j]};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
            }
        }
        return st.size();
    }
};