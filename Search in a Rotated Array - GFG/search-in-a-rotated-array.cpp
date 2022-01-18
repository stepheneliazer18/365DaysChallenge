// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    int search(int nums[], int l, int h, int target){

        int start = l;
        int end = h;
        
        while (start <= end){
            
            int mid = (start+end)/2;
            
            if(nums[mid]==target) return mid;
            
            if(nums[start] <= nums[mid]){
                if(nums[start]<=target && target<nums[mid]) end = mid-1;
                else start = mid+1;
            }
            if(nums[mid]<=nums[end]){
                if(nums[mid]<target && target<=nums[end]) start = mid+1;
                else end = mid-1;
            }
        }
        return -1;
    }
};

// { Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}  // } Driver Code Ends