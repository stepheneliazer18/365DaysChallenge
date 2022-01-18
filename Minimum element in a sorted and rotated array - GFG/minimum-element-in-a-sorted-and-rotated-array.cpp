// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int findMin(int nums[], int n){
        
        if(n==1) return nums[0];
        
        if (nums[0] < nums[n - 1]) return nums[0];
        
        int start = 0;
        int end = n - 1;
        while (start < end){
            
            int mid = (start+end)/2;
            
            if (nums[mid] > nums[mid + 1]) return nums[mid + 1];
            
            if(nums[start] > nums[mid] && nums[mid] < nums[end]) end = mid;
            else start = mid;
        }
        return 0;
    }
};

// { Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution ob;
		cout<<ob.findMin(a, n)<<endl;
	}
	return 0;
}  // } Driver Code Ends