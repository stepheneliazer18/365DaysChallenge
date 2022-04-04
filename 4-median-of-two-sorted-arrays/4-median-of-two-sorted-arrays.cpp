class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        
        if(n > m){
            swap(n,m);
            swap(nums1,nums2);
        }

        int low = 0;
        int high = n;
        
        while(low <= high){
            int cut1 = (low+high) >> 1;
            int cut2 = (n+m+1)/2 - cut1;
            
            int l1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
            int l2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];
            int r1 = cut1 == n ? INT_MAX : nums1[cut1];
            int r2 = cut2 == m ? INT_MAX : nums2[cut2];
            
            if(l1 <= r2 && l2 <= r1){
                if((m+n) % 2) return max(l1,l2);
                else return (max(l1,l2) + min(r1,r2)) / 2.0;
            }
            if(l1 > r2) high = cut1 - 1;
            if(l2 > r1) low = cut1 + 1;
        }
        return 0.0;
    }
};