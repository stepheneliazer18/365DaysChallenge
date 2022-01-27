class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;

        
        int l=0;
        int r = n-1;
        for(l=0;l<n-1;l++){
            if(nums[l] > nums[l+1])break;
        }
        for(r=n-1;r>0;r--){
            if(nums[r] < nums[r-1])break;
        }
        
        if(l==n || r==0) return 0;
        
        cout<<"l = "<<l<<" r = "<<r<<endl;
        
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i=l;i<=r;i++){
            mini = min(mini, nums[i]);
            maxi = max(maxi, nums[i]);
        }
        
        cout<<"mini = "<<mini<<" maxi = "<<maxi<<endl;
        
        l = 0;
        r = n-1;
        for(l=0;l<n;l++){
            cout<<mini<<" > "<<nums[l]<<endl;
            if(mini < nums[l]) break;
        }
        for(r = n-1;r>=0;r--){
            cout<<maxi<<" > "<<nums[r]<<endl;
            if(maxi > nums[r]) break;
        }
        
        cout<<"l = "<<l<<" r = "<<r<<endl;

        if(l>r) return 0;
        return r-l+1;
    }
};
/*

[2,6,4,8,10,9,15]
[1,2,3,4]
[1]
[2,1]
[1,2,3,3,3]
[1,3,2,2,2]
[2,3,3,2,4]

*/