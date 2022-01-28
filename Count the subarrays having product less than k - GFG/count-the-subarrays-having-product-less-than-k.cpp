// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& nums, int n, long long k) {
        if(k<=1) return 0;
        int cnt = 0;
        
        int l = 0;
        int r = 0;
        
        long long prod = 1;
        while(r<n){
            prod *= nums[r];
            
            while(prod >= k){
                prod/=nums[l];
                l++;
            }
            
            cnt += r-l+1;
                
            r++;
        }
        
        return cnt;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends