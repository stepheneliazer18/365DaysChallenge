// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int findPlatform(int arr[], int dep[], int n)
    {
        sort(arr, arr + n);
        sort(dep, dep + n);

    	int cur = 1;
    	int maxi = 1;
    	
    	int start = 1;
    	int end = 0;
    	
    	while(start<n){
    	    if(arr[start] <= dep[end]){
    	        cur++;
    	        start++;
    	    }
    	    else{
    	        cur--;
    	        end++;
    	    }
    	    maxi = max(maxi,cur);
    	}
    	return maxi;
    }
};


// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}  // } Driver Code Ends