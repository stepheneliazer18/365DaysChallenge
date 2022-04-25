class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = m+n;
        
        while(n && m){
            if(nums2[n-1] >= nums1[m-1]) nums1[--k] = nums2[--n];
            else nums1[--k] = nums1[--m];
        }
        while(n) nums1[--k] = nums2[--n];
    }
};