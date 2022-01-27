class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        vector<int> temp = nums;
        sort(temp.begin(),temp.end());
        
        for(auto &it: nums)cout<<it<<" ";
        cout<<endl;
        for(auto &it: temp) cout<<it<<" ";
        cout<<endl;
        
        int l=0;
        int r = n-1;
        for(l=0;l<n;l++){
            if(nums[l]!=temp[l])break;
        }
        for(r=n-1;r>=0;r--){
            if(nums[r]!=temp[r])break;
        }
        
        cout<<"l = "<<l<<" r = "<<r<<endl;
        
        if(l>r) return 0;
        
        return r-l+1;
    }
};