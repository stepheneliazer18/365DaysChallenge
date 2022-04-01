// { Driver Code Starts
#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    vector<int> RopeCutting(int arr[], int n){
        vector<int> res;
        map<int,int> mp;
        for(int i=0;i<n;i++) mp[arr[i]]++;
        
        for(auto &it: mp){
            res.push_back(n-it.second);
            n-=it.second;
        }
        if(mp.size()==1) return {0};
        res.pop_back();
        return res;
    }
};

// { Driver Code Starts.
int main()
{   
    int T;
    cin>> T;
    while(T--)
    {
       	int n;
       	cin>>n;
       	int arr[n+1];
       	for(int i=0;i<n;i++)
       	   cin>>arr[i];
        
        vector<int> v;
        Solution ob;
        v = ob.RopeCutting(arr, n);
        for(int i : v){
            cout << i << " ";
        }
        cout << endl;
        
        
    }
  return 0;
}  // } Driver Code Ends