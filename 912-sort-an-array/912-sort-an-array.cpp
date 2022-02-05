class Solution {
public:
    void Merge(vector<int>& nums, int l, int mid, int r){
        
        vector<int> left;
        vector<int> right;
        for(int i=l;i<=mid;i++) left.push_back(nums[i]);
        for(int i=mid+1;i<=r;i++) right.push_back(nums[i]);
        
        int f = 0, s = 0;
        
        while(f<left.size() && s<right.size()){
            if(left[f] < right[s]) nums[l++] = left[f++];
            else nums[l++] = right[s++];
        } 
        
        while(f<left.size()) nums[l++] = left[f++];
        while(s<right.size()) nums[l++] = right[s++];
    }
    void mergeSort(vector<int>& nums, int l,int r){
        if(l<r){
            int mid = (l+r)/2;
            
            mergeSort(nums,l,mid);
            mergeSort(nums,mid+1,r);
            
            Merge(nums,l,mid,r);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};