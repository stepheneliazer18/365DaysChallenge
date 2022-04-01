// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
/*You are required to complete this method */

class Solution
{
    public:
    int josephus(int n, int k){
       vector<int> vec;
       for(int i=1;i<=n;i++) vec.push_back(i);
       
       int len = n;
       int i=0;
       int cnt = 1;
       while(len>1){
           if(vec[i]!=-1){
               if(cnt == k){
                   vec[i] = -1;
                   len--;
                   cnt = 1;
                   
               }
               else cnt++;
           }
           i = (i+1)%n;
       }
       for(int i=0;i<n;i++){
           if(vec[i]!=-1) return i+1;
       }
       return 1;
    }
};



// { Driver Code Starts.

int main() {
	
	int t;
	cin>>t;//testcases
	while(t--)
	{
		int n,k;
		cin>>n>>k;//taking input n and k
		
		//calling josephus() function
		Solution ob;
		cout<<ob.josephus(n,k)<<endl;
	}
	return 0;
}  // } Driver Code Ends