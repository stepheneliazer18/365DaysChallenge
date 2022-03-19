// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    long long maxSubarraySum(int arr[], int n){
        
        long long sum = 0;
        long long ans = 0;
        bool flag = true;
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            maxi = max(maxi,arr[i]);
            if(arr[i] >= 0) flag = false;
            sum += arr[i];
            if(sum < 0) sum = 0;
            ans = max(sum,ans);
        }
        if(flag) ans = maxi;
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}
  // } Driver Code Ends