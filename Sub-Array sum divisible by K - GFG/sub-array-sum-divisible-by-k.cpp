// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	long long subCount(long long nums[], int N, long long k)
	{
	    int n = N;
        if(n==1) return nums[0]%k==0;
        long long cnt = 0;
        unordered_map<int,int> mp;
        int sum = 0;
        mp[0]=1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int rem = sum%k;
            if(rem<0) rem+=k;
            if(mp[rem]){
                cnt+=mp[rem];
                mp[rem]++;
            }
            else mp[rem]++;
        }
        return cnt;
	}



};


// { Driver Code Starts.

int main() 
{
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
       	long long k;
		cin>>n >> k;
		long long a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
        

        Solution ob;
        cout << ob.subCount(a, n, k);
	    cout << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends