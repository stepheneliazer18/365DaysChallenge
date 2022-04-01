// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
/*You are required to complete this method */

class Solution
{
    public:
    void fun(vector<int>& vec, int i, int &ans, int k){
        if(vec.size()==1){
            ans = vec[0];
            return;
        }
        i = (i+k-1)%vec.size();
        vec.erase(vec.begin()+i);
        fun(vec,i,ans,k);
    }
    int josephus(int n, int k){
       vector<int> vec;
       int ans = -1;
       for(int i=1;i<=n;i++) vec.push_back(i);
       
       fun(vec,0,ans,k);
       
       return ans;
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