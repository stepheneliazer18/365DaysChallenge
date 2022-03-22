// { Driver Code Starts
#include <iostream>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int equilibriumPoint(long long vec[], int n) {
        
        long long p[n];
        long long s[n];

	    int temp = 0;
	    for(int i=0;i<n;i++){
	        temp += vec[i];
	        p[i] = temp;
	    }
	    
	    temp = 0;
	    for(int i=n-1;i>=0;i--){
	        temp += vec[i];
	        s[i] = temp;
	    }
	    
	    int ans = 100000005;
	    
	    for(int i=0;i<n;i++){
	        if(i==0){
	            if(s[i+1] == 0) ans = min(ans,i+1);
	        }
	        else if(i==n-1){
	            if(p[i-1] == 0) ans = min(ans,i+1);
	        }
	        else{
	            if(p[i-1] == s[i+1]) ans = min(ans,i+1);
	        }
	    }
	    
	    if(n==1) return 1;
	    else if(ans == 100000005) return -1;
	    else return ans;
    }
};

// { Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends